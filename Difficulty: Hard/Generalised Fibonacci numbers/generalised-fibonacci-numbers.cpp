#define ll long long
class Solution {
  public:
    
    ll Mod;
    vector<vector<ll>> multiply( vector<vector<ll>>&a ,vector<vector<ll>>&b ){
        int n=a.size();
        vector<vector<ll>> ans(n,vector<ll>(n,0));
     
        for(int i=0;i<n;i++)
          for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
              ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%Mod;
    
        return ans;
    }
    
    vector<vector<ll>> matrix_expo(vector<vector<ll>>&mat,ll times){
        int n=mat.size();
        vector<vector<ll>> ans(n,vector<ll>(n,0));
        for(int i=0;i<n;i++)
          ans[i][i]=1;
     
        while(times>0){
          if(times%2==1)
          ans=multiply(ans,mat);
          mat=multiply(mat,mat);
          times>>= 1;
        }
        return ans;
    }
    
    
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
       Mod = m;
       if(n<=2) return 1;
        vector<vector<ll>> mat= {{0,1,0},{b,a,c},{0,0,1}};
        vector<vector<ll>> ans= matrix_expo(mat,n-2);
        
        
    return (ans[1][0] + ans[1][1] + ans[1][2])%Mod;   
    }
    
};