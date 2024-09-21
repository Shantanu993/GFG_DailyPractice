//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    # define MOD 1000000007
    
    int solve(int n){
        
        vector<long long> dp(n+1,0);
      
        for(int i=1; i<=n; i++){
            
            if( i <= 2)
               dp[i] = i;
            else
               dp[i] = ((dp[i-1]%MOD) + ((i-1)*dp[i-2])%MOD)%MOD;
                
        }
        
        return dp[n];
       
    }

    int countFriendsPairings(int n) 
    { 
        // code here
        
         return solve(n);
    }
};    
  
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends