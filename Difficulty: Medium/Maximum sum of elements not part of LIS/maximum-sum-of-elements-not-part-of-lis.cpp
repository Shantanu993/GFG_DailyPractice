class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int totSum = 0;
        for(auto it:arr) totSum+=it;
        int n = arr.size();
        vector<pair<int,int>>dp; //{len,min_sum}
        for(int i = 0 ; i<n;i++){
            dp.push_back({1,arr[i]});
        }
        for(int curr = 1;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(arr[prev]<arr[curr]){
                    if(dp[prev].first+1 > dp[curr].first){
                        dp[curr] = {dp[prev].first + 1, arr[curr] + dp[prev].second};
                    }
                    else if(dp[prev].first+1 == dp[curr].first){
                        dp[curr] = {dp[curr].first,min(dp[curr].second,dp[prev].second+arr[curr])};
                    }
                }
            }
        }
        int minSumLis = 0;
        int maxLen = 0;
        for(auto it:dp){
            if(it.first>maxLen){
                maxLen = it.first;
                minSumLis = it.second;
            }
            else if(it.first==maxLen) minSumLis = min(minSumLis,it.second);
            
        }

        return totSum-minSumLis;
        
    }
};