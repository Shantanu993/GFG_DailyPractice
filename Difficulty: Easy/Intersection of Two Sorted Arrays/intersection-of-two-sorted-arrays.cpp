class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int n1=a.size();
        int n2=b.size();
        
        if(n1==0 || n2==0){
            return {};
        }
        
        if(a[n1-1]<b[0]){
            return {};
        }
        
        vector<int> ans;
        unordered_map<int,bool> mp;
        
        int i=0,j=0;
        
        while(i<n1 && j<n2){
            if(a[i]==b[j] && mp[a[i]]==false) {
                ans.push_back(a[i]);
                mp[a[i]]=true;
            }
            else if(a[i]<b[j]){
                i++;
            }
            else{
                j++;
            }
        }
        
        return ans;
    }
};