class Solution {
  public:
  
  vector<int>helper(vector<int> &arr){
      
      // just finds the lis
      
      int n = arr.size();
      vector<int>dp(n,1);
      
      for(int i=0; i<n; i++){
          for(int j=0; j<i; j++){
              if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                  dp[i] = dp[j] + 1;
              }
          }
      }
      
      return dp;
  }
  
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int>dp1 = helper(nums);
        
        reverse(nums.begin(),nums.end());
        
        int ans = 0;
        
        vector<int>dp2 = helper(nums);
        reverse(dp2.begin(),dp2.end());
        // inorder to fix the reversed indexes
        
        for(int i=0; i<n; i++){

             // ********
            // *******
           // ******
            // this is very very important observation people are missing
            if(dp1[i]!=1 && dp2[i]!=1)
            ans = max(ans,dp1[i]+dp2[i]-1);
        }
        
        return ans;
    }
};