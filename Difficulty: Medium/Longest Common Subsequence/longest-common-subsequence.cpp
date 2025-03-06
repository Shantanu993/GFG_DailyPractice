//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  int helper(int idx1,int idx2,string &s1, string &s2,vector<vector<int>> &dp)
    {
        if(idx1 < 0 || idx2 < 0)
        {
            return 0;
        }
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
            
        int len = INT_MIN;
        if(s1[idx1] == s2[idx2])
        {
            len = max(len, 1 + helper(idx1-1,idx2-1,s1,s2,dp));
        }
        else
        {
            len = max(len,max(helper(idx1-1,idx2,s1,s2,dp), helper(idx1,idx2-1,s1,s2,dp)));
        }
        return dp[idx1][idx2]=len;
    }
    int lcs(string &s1, string &s2) {
        // code here
           vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));    
        return helper(s1.size()-1, s2.size()-1,s1,s2,dp);
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends