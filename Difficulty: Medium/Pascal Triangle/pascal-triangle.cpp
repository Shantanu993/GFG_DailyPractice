//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution {
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> ans(n, 1);
        long long mod = 1000000007;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j > 0; j--) {
                ans[j] = (ans[j] + ans[j - 1]) % mod;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends