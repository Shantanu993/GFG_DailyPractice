class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int>m;
        int start=0;
        int end = 0;
        int ans = 0;
        m[arr[0]]++;
        
        while(end<n){
            
            if(m.size()<=2){
                ans=max(ans,end-start+1);
                end++;
                if(end<n)m[arr[end]]++;
            }
            else{
                m[arr[start]]--;
                if(m[arr[start]]==0)m.erase(arr[start]);
                start++;
            }
        }
        
        return ans;
    }
};