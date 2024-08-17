//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int maxval = 0; 

        for (int i = 0; i < n; i++) {
            maxval = max(arr[i], maxval);
        }

        vector<vector<int>> dp(2 * maxval + 1, vector<int>(n, 0));

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int dif = arr[i] - arr[j] + maxval;

                dp[dif][i] = dp[dif][j] + 1;

                ans = max(ans, dp[dif][i]);
            }
        }

        return ans + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends