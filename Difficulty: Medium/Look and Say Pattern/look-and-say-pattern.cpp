//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to generate the look-and-say sequence.
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string curr = "1";

        // Start from the second term, build every term
        // terms using the previous term
        for (int i = 2; i <= n; i++) {
            string next = "";

            int cnt = 1;

            for (int j = 1; j < curr.length(); j++) {

                // If same as previous, then increment
                // count
                if (curr[j] == curr[j - 1]) {
                    cnt++;

                    // If different process the previous
                    // character and its count and reset
                    // count for the current character
                } else {
                    next += to_string(cnt) + curr[j - 1];
                    cnt = 1;
                }
            }

            next += to_string(cnt) + curr.back();
            curr = next;
        }

        return curr;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends