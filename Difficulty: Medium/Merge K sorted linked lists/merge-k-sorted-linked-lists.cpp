class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        int i = 0;
        Node* le = nullptr;
        Node* h = arr[0];
        vector<int> a;
        while(i < n){
          if(le) le->next = arr[i];
          Node* t = arr[i];
          while(t->next) t = t->next;
          le = t;
          i++;
        }
        Node* d = h;
        while(d){
          a.push_back(d->data);
          d = d->next;
        }
        sort(a.begin(),a.end());
        d = h;
        i = 0;
        while(d){
          d->data = a[i];
          d = d->next;
          i++;
        }
        return h;
    }
};