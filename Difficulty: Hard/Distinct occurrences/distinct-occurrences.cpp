//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
  public:
  
    int solveUsingRec(string &s, string &t, int i, int j){
        // base case
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }

        int ans = 0;
        if(s[i]==t[j]){
            // include
            ans+=solveUsingRec(s, t, i+1, j+1);
        }
        // exclude and chacter not match also
        ans+=solveUsingRec(s, t, i+1, j);
        return ans;
    }
    
    int solveUsingMem(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        // base case
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;
        if(s[i]==t[j]){
            // include
            ans+=solveUsingMem(s, t, i+1, j+1, dp);
        }
        // exclude and chacter not match also
        ans+=solveUsingMem(s, t, i+1, j, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }

  
    int subsequenceCount(string& txt, string& pat) {
        // code here
        // int ans = solveUsingRec(txt, pat, 0, 0);
        
        vector<vector<int>> dp(txt.size(), vector<int>(pat.size(), -1));
        int ans = solveUsingMem(txt, pat, 0, 0, dp);
        return ans;
    }
};

//{ Driver Code Starts.

//  Driver code to check above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends