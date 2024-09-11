//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int dp[220][220][2];
    int mod=1003;
    int boolPar(int i,int j,bool isTrue,int &n,string s){
        if(i>j) return 0;
        if(i==j){
            if(isTrue){
                if(s[i]=='T') return 1;
                else return 0;
            }
            else{
                return s[i]=='F';
            }
        }
        if(j-i==2){
            char op=s[i+1];
            char var1=s[i],var2=s[j];
            if(isTrue){
                if(op=='&'){
                    if(var1=='F' || var2=='F') return 0;
                    return 1;
                }
                else if(op=='|'){
                    if(var1=='T' || var2=='T') return 1;
                    return 0;
                }
                else if(op=='^'){
                    if(var1==var2) return 0;
                    return 1;
                }
            }
            else{
                if(op=='&'){
                    if(var1=='F' || var2=='F') return 1;
                    return 0;
                }
                else if(op=='|'){
                    if(var1=='T' || var2=='T') return 0;
                    return 1;
                }
                else if(op=='^'){
                    if(var1==var2) return 1;
                    return 0;
                }
            }
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ans=0;
        for(int k=i+1;k<j;k++){
            if(s[k]=='&' || s[k]=='|' || s[k]=='^'){
                int lt=0,lf=0,rt=0,rf=0;
                lt=boolPar(i,k-1,true,n,s);
                lf=boolPar(i,k-1,false,n,s);
                rt=boolPar(k+1,j,true,n,s);
                rf=boolPar(k+1,j,false,n,s);
                
                if(s[k]=='&'){
                    if(isTrue) ans=(ans+(lt*rt)%mod)%mod;
                    else ans=(ans+((lf*rt)+(lt*rf)+(lf*rf))%mod)%mod;
                }
                else if(s[k]=='|'){
                    if(isTrue)ans=(ans+(lt*rt+lf*rt+lt*rf)%mod)%mod;
                    else ans=(ans+(lf*rf)%mod)%mod;
                }
                else if(s[k]=='^'){
                    if(isTrue)ans=(ans+(lf*rt+lt*rf)%mod)%mod;
                    else ans=(ans+((lt*rt+lf*rf)%mod))%mod;
                }
            }
        }
        return dp[i][j][isTrue]=ans;
    }

    int countWays(int n, string s){
        // code here
        memset(dp,-1,sizeof(dp));
        int ans=boolPar(0,n-1,true,n,s);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends