class Solution {
  public:
     int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp (x + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= m; k++){
                    if(i >= k){
                        dp[i][j] += dp[i - k][j -  1];
                    }
                }
            }
        }
        return dp[x][n];
    }
};