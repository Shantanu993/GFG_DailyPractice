//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        map<string, int> m;
        int n = s.size();
    
        // table for storing results (2 rows for odd-
        // and even-length palindromes
        int R[2][n + 1];
    
        // Find all sub-string palindromes from the given input
        // string insert 'guards' to iterate easily over s
        s = "@" + s + "#";
    
        for (int j = 0; j <= 1; j++) {
            int rp = 0; // length of 'palindrome radius'
            R[j][0] = 0;
    
            int i = 1;
            while (i <= n) {
                // Attempt to expand palindrome centered at i
                while (s[i - rp - 1] == s[i + j + rp])
                    rp++; // Incrementing the length of palindromic
                          // radius as and when we find vaid palindrome
    
                // Assigning the found palindromic length to odd/even
                // length array
                R[j][i] = rp;
                int k = 1;
                while ((R[j][i - k] != rp - k) && (k < rp)) {
                    R[j][i + k] = min(R[j][i - k], rp - k);
                    k++;
                }
                rp = max(rp - k, 0);
                i += k;
            }
        }
    
        // remove 'guards'
        s = s.substr(1, n);
    
        // Put all obtained palindromes in a hash map to
        // find only distinct palindromess
        m[string(1, s[0])] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++)
                for (int rp = R[j][i]; rp > 0; rp--)
                    m[s.substr(i - rp - 1, 2 * rp + j)] = 1;
            m[string(1, s[i])] = 1;
        }
    
        return (m.size() - 1);
    }
};


//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends