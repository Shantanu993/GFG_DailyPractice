//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod = 1e9+7;
	
	    int solve(string &str,vector<int> &dp,int ind){
	        if(ind == str.length())return 1;
	        if(str[ind]=='0')return 0;
	        
	        if(dp[ind]!=-1)return dp[ind];
	        
	        int one = 0,two = 0;
	        
	        one = solve(str,dp,ind+1);
	        if(ind<str.length()-1){
	            int num = str[ind]-'0';
	            num = num*10;
	            num+=str[ind+1]-'0';
	            
	            if(num<=26){
	                two = solve(str,dp,ind+2);
	            }
	        }
	        
	        return dp[ind] = (one+two)%mod;
	    }
	    
		int CountWays(string str){
		    int n = str.length();
		    vector<int> dp(n+1,-1);
		    
		    return solve(str,dp,0);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends