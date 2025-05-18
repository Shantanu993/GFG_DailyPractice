//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long


// } Driver Code Ends

// User function template for C++
class Solution {

  public:
    // Function to count the number of strings.
    int countStrings(int n) {
        int a[n], b[n];
        a[0] = b[0] = 1;
        // Loop to calculate the number of strings.
        for (int i = 1; i < n; i++) {
            // Calculating a[i] and b[i] based on previous values.
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }
        // Returning the sum of a[n-1] and b[n-1].
        return a[n - 1] + b[n - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.countStrings(n);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends