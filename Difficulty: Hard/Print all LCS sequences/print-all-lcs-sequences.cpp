class Solution {
  public:
  vector<vector<int>>dp;
  vector<vector<set<string>>>memo;
  
   set<string> bkt(int i , int j ,string &s1, string &s2 ){
       if(i==0 || j==0) return {""};
       if(!memo[i][j].empty()) return memo[i][j];
       
       set<string>res;
       
       if(s1[i-1]==s2[j-1]){
           auto prev = bkt(i-1,j-1, s1, s2);
           for(auto &s: prev){
               res.insert(s+s1[i-1]);
           }
       }else{
           
           if(dp[i-1][j]>=dp[i][j-1]){
               auto l1= bkt(i-1, j, s1,s2);
               res.insert(l1.begin(), l1.end());
           }
           if(dp[i-1][j]<=dp[i][j-1]){
               auto l2= bkt(i, j-1, s1,s2);
               res.insert(l2.begin(), l2.end());
           }
           
       }
       
       return memo[i][j] = res;
   }
    vector<string> allLCS(string &s1, string &s2) {
        // Code here
        int m=s1.length(), n=s2.length();
        dp.assign(m+1, vector<int>(n+1,0));
        memo.assign(m+1, vector<set<string>>(n+1, set<string>() ));
        
        for(int i=1; i<=m;i++){
            for(int j=1; j<=n;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]= max (dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        set<string>lcsset = bkt(m,n, s1, s2);
        return vector<string>(lcsset.begin(), lcsset.end());
    }
};