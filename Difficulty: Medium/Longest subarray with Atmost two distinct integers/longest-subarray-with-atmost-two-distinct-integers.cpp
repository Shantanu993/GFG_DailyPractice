class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0, j=0, cnt=0, maxi=1;
        unordered_map<int, int>mp;
        
        for(; j<n; j++){
            if(mp[arr[j]]==0){
                cnt++;
            }
            mp[arr[j]]++;
            for(; i<n && cnt>2; i++){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    cnt--;
                    mp.erase(arr[i]);
                }
            }
            maxi=max(maxi, (j-i+1));
        }
        
        return maxi;
    }
};