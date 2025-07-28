class Solution {
  public:
  int mod=1e9+7;
  int fib(long long int n)
{
   vector<vector< long long int>> F = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return F[0][0];
}
 
// Optimized version of power() in method 4
void power(vector<vector< long long int>> &F, long long int n)
{
    if(n == 0 || n == 1)
       return;
    vector<vector< long long int>>  M = {{1, 1}, {1, 0}};
    vector<vector<long long int>> ans={{1,0},{0,1}};
    while(n>0)
    {
    if(n%2==0)
    {
       F = multiply(F,F);
        n/=2;
    }
    else
    {
       ans= multiply(ans,F);
        n=n-1;
    }
    
    }
    F=ans;
    
}
 
vector<vector<long long int>> multiply(vector<vector<long long int>> F, vector<vector<long long int>> M)
{
    long long int x = (F[0][0] * M[0][0] + F[0][1] * M[1][0])%mod;
     long long int y =( F[0][0] * M[0][1] + F[0][1] * M[1][1])%mod;
     long long int z = (F[1][0] * M[0][0] + F[1][1] * M[1][0])%mod;
     long long int w = (F[1][0] * M[0][1] + F[1][1] * M[1][1])%mod;
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
    return F;
}
    int countStrings(long long int N) {
       
     
     return fib(N+2);
    
    }
};