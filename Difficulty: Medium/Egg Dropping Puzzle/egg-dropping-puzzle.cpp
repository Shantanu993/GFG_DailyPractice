//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    
    int fun(int n,int k,vector<vector<int>> &dp){
        if(n==0)
            return 0;
        if(k==1 || k==0 || n==1)
            return k;    
        
        if(dp[n][k]!=-1)
            return dp[n][k];
        int temp=INT_MAX;
        for(int i=1;i<=k;i++){
            int z=1+max(fun(n-1,i-1,dp),fun(n,k-i,dp));  //tuta,natuta
            temp=min(temp,z);
        }
        return dp[n][k]=temp;
        
    }
    
    
    
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return fun(n,k,dp);
    }


};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends