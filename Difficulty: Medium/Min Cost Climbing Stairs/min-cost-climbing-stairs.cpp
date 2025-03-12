//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int N = cost.size();
        vector<int> dp(N+2,0);
        
        for(int i=N-1; i>=0 ; --i)
        {
            dp[i] = min(dp[i+1] , dp[i+2]) + cost[i];
        }
        
        return min(dp[0], dp[1]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends