//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M){
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i = 0;i<n;i++){
           dp[i][m-1] = M[i][m-1]; 
       }
       
       for(int j = m-2;j>=0;j--){
            for(int i = 0;i<n;i++){
                 int right = 0;
                 int updig = 0;
                 int downdig = 0;
                 if(j+1<m) right = dp[i][j+1];
                 if(i-1>=0 && j+1<m) updig = dp[i-1][j+1];
                 if(i+1<n && j+1<m ) downdig = dp[i+1][j+1];
                 dp[i][j] = M[i][j]+max({right,updig,downdig});
            }
       }
       int ans = INT_MIN;
       for(int i = 0;i<n;i++){
            ans = max(ans,dp[i][0]);
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends