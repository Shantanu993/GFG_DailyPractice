//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
 
    int cutRod(int price[], int N) {
        int sum=N;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,0));
        
        //dp[i][j] means i elements  and length of rod is j 
        for(int i=1;i<=N;i++)
        for(int j=1;j<=sum;j++)
        if(j>=i)dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-i]);
        else dp[i][j]=dp[i-1][j];;
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends