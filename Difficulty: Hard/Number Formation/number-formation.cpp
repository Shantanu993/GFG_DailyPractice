class Solution {

  public:
    int getSum(int x, int y, int z) {
        // Your code goes here
        int cnt[101][101][101]={0};
        int v[101][101][101]={0};
        const int mod = 1e9+7;
        cnt[0][0][0]=1;
        v[0][0][0]=0;
        int tsm=0;
        
        for(int i=0;i<=x; i++){
            for(int j=0; j<=y; j++){
                for(int k=0; k<=z; k++){
                    if(i>0){
                        v[i][j][k] = (v[i][j][k]+ (1LL * v[i-1][j][k]*10%mod + 1LL * cnt[i-1][j][k] *4 %mod )%mod)%mod;
                        cnt[i][j][k]= (cnt[i][j][k] + cnt[i-1][j][k])%mod;
                    }
                    if(j>0){
                        v[i][j][k] = (v[i][j][k]+ (1LL * v[i][j-1][k]*10%mod + 1LL * cnt[i][j-1][k] *5 %mod )%mod)%mod;
                        cnt[i][j][k]= (cnt[i][j][k] + cnt[i][j-1][k])%mod;
                    }
                    if(k>0){
                        v[i][j][k] = (v[i][j][k]+ (1LL * v[i][j][k-1]*10%mod + 1LL * cnt[i][j][k-1] *6 %mod )%mod)%mod;
                        cnt[i][j][k]= (cnt[i][j][k] + cnt[i][j][k-1])%mod;
                    }
                     tsm = (tsm + v[i][j][k]) % mod;
                }
            }
           
        }
        return tsm;
    }
};