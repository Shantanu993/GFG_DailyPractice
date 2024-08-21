//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {


  public:
 
int rec(vector<int> &coins, int sum, int cursum,  vector<int>&dp) {
    // Base case: If cursum equals the sum, no more coins are needed
    if (cursum == sum) {
        return 0;
    }
    
    // If cursum exceeds the sum, it's not a valid combination
    if (cursum > sum) {
        return INT_MAX;
    }
    
    if(dp[cursum]!=-1)
    return dp[cursum];
    int coin = INT_MAX; // Initialize to a large number
    
    // Try every coin
    for (int i = 0; i < coins.size(); i++) {
        int res = rec(coins, sum, cursum + coins[i],dp);
        
        if (res != INT_MAX) {
            coin = min(coin, res + 1);
        }
    }
    
    
    return dp[cursum]=coin;
}
  
  
    int minCoins(vector<int> &coins, int sum) {
        vector<int>dp(sum+1,-1);
       
  int result= rec(coins,sum,0,dp);
  return result == INT_MAX ? -1 : result;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends