//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        
    if (s1.length() != s2.length()) return false;
     
    string combined = s1 + s1;

    int n = s2.length();
    vector<int> lps(n, 0); 

    int len = 0;
    for (int i = 1; i < n; ) {
        if (s2[i] == s2[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    int i = 0, j = 0; 
    while (i < combined.length()) {
        if (s2[j] == combined[i]) {
            i++; j++;
        }
        if (j == n) return true; 
        if (i < combined.length() && s2[j] != combined[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }

    return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends