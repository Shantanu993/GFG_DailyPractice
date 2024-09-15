//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum = 0;
        int MOD = 1e9+7;
        for(int i=0;i<n;i++){
            totSum+=arr[i];
        }
        if((totSum-d)<0 || (totSum-d)%2!=0)
            return 0;
        int target = (totSum-d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        dp[0][0] = 1;
        if(arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }
        if(arr[0] == 0) { 
            dp[0][0] = 2; 
        }
        
        for(int i=1;i<n;i++)
        {
            for(int sum=0;sum<=target;sum++)
            {
                int nontake = dp[i-1][sum];
                int take = 0;
                if(arr[i]<=sum)
                    take = dp[i-1][sum-arr[i]];
                dp[i][sum] = (take+nontake)%MOD;
            }
        }
        return dp[n-1][target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends