//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        int n=s.size();
        string s1="";
        for(int i=0;i<n;i++)s1=s[i]+s1;

        vector<int>a(n+1,0);
        // for(int i=0;i<=n;i++)
        // a[i]=i;
        for(int i=1;i<=n;i++)
        {
            vector<int>b(n+1,0);
            // b[0]=i;
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s[j-1])
                {
                    b[j]=1+a[j-1];
                }
                else
                {
                    b[j]=max(b[j-1],a[j]);
                }
            }
            a=b;
        }
        return a[n];
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends