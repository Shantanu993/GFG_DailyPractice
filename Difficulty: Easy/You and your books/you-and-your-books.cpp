//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    long long max_Books(int arr[], int n, int k) {
        long long dp[n];
        long long max_books = 0;
        
        // Initialize dp array
        dp[0] = (arr[0] <= k) ? arr[0] : 0;
        max_books = dp[0];
        
        for (int i = 1; i < n; i++) {
            if (arr[i] <= k) {
                dp[i] = arr[i] + dp[i-1];
            } else {
                dp[i] = 0;
            }
            max_books = max(max_books, dp[i]);
        }
        
        return max_books;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends