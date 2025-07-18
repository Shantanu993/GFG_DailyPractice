class Solution {
  public:
     int distinctSubsequences(string s) {
        // code  here
        int n=s.length();
        int mod=1e9+7;
        int v=0, v1=1;
        unordered_map<char,int>lstoccurance, val;
       
        
        for(int i=1;i<=n; i++){
            char ch= s[i-1];
            v= 2*v1%mod;
            
            if(lstoccurance.count(ch)){
                
                v =(v-val[ch]+mod)%mod;
            }
            lstoccurance[ch]=i;
            val[ch]=v1;
            v1=v;
        }
        
        return v;
    }
};