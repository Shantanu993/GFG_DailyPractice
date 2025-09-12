class Solution {
    private:
    int getans(int n, vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int ans=n;
        for (int i=1;  i*i<=n; i++){
            int temp=i*i;
            ans= min(ans, 1+getans(n-temp, dp));
        }
        dp[n]= ans;
        return dp[n];
    }
  public:
    int MinSquares(int n) {
        // Code here
        vector<int> dp(n+2, -1);
        return getans(n, dp);
    }
};