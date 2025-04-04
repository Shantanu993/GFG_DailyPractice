//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        
            if (n + m != s3.size()) return false;
        //filling first row //s2
        for(int j=1;j<=m;j++)
        {
            dp[0][j]=dp[0][j-1] && (s2[j-1]==s3[j-1]); 
        }
        //filling first col //s1
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0] && (s1[i-1]==s3[i-1]); 
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int k=i+j-1;
                dp[i][j]=(dp[i-1][j] and s1[i-1]==s3[k]) or (dp[i][j-1] and s2[j-1]==s3[k]);
            }
        }
        return dp[n][m];
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        if (obj.isInterleave(a, b, c))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends