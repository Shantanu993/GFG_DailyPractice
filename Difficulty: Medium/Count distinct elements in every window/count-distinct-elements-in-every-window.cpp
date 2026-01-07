class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int>ans;
        unordered_map<int, int>mp;
        for(int i=0; i<k; i++){mp[arr[i]]++;}
        ans.push_back(mp.size());
        for(int i=k, j=0; i<arr.size(); i++, j++){
            mp[arr[j]]--;
            if(mp[arr[j]]==0){mp.erase(arr[j]);}
            mp[arr[i]]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};