//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rec(int i, int buy, int times, int n, vector<int>&prices,vector<vector<vector<int>>>&dp){
        int profit = 0;
        if (times<=0 || i==n) return 0;
        if (dp[i][buy][times]!=-1) return dp[i][buy][times];

        if (buy){
            profit = max(-prices[i]+rec(i+1, 0, times, n, prices, dp), rec(i+1,1, times, n, prices, dp));
        }
        else{
            profit = max(prices[i]+rec(i+1, 1, times-1, n, prices, dp),rec(i+1,0,times, n, prices, dp));
        }
        return dp[i][buy][times] = profit;
    }
  
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return rec(0, 1, k, n, prices, dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends