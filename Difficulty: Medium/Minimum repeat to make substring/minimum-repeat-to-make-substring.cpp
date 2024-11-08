//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        // Step 1: Initialize the concatenated string `s3` with `s1` and counter for repetitions
        string s3 = s1;
        int cnt = 1;
        
        // Step 2: Keep concatenating `s1` until `s3`'s length is at least the length of `s2`
        while (s3.length() < s2.length()) {
            s3 += s1;
            cnt++;
        }
        
        // Step 3: Check if `s2` is a substring of `s3`
        if (s3.find(s2) != string::npos) return cnt;
    
        // Step 4: Concatenate one more time to cover the overlap cases
        s3 += s1;
        cnt++;
    
        // Step 5: Check again if `s2` is now a substring
        if (s3.find(s2) != std::string::npos) return cnt;
    
        // If `s2` is still not found, return -1
        return -1;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends