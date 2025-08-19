class Comp {
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first)return a.second>b.second;
        return a.first>b.first;
    }
    
};
class Solution {
  public:
  
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int idx=-1;
        vector<int> ans(n,-1);
        while(!pq.empty()){
            int val=pq.top().first;
            int i=pq.top().second;
            if(idx<i or val==arr[idx]){
                ans[i]=-1;
                idx=i;
            }
            else ans[i]=idx;
            pq.pop();
            
            
        }
        return ans;
        
    }
};