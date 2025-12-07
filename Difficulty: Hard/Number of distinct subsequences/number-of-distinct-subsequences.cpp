class Solution {
  public:
    int mode = 1000000007;
    virtual int distinctSubseq(string &str){
      int n = str.size();
      vector<long long int> dp(n+1, 0);
      vector<int> last(26, -1);
      dp[0] = 1LL;
      
      for(int i=1; i<=n; i++){
        dp[i] = (2*dp[i-1])%mode;
        int ind_ch = (str[i-1] - 97);
        if(last[ind_ch] != -1)
          dp[i] = (dp[i] - dp[last[ind_ch]] + mode)%mode;
        
        last[ind_ch] = i-1;
        
      }
      
      return (int)(dp[n]%mode);
    }
};