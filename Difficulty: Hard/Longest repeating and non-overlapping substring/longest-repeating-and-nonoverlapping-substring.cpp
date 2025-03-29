//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestSubstring(string& s) {
    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int start = 0, length = 0;
    //if(s== "abaabbbbbaa") return "baa";
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i != j && s[i-1] == s[j-1]) {
                dp[i][j] = 1+min(dp[i-1][j-1], j-i-1);
                
                // Update length and starting index
                if (dp[i][j] > length) {
                    length = dp[i][j];
                    start = i - length;
                }
            } 
        }
    }

    /*cout << "Start: " << start << " Length: " << length << endl;
    cout << "DP Table:" << endl;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    if (length == 0) return "-1";
    return s.substr(start, length);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends