//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
    
    int countgroup(vector<int>& arr) {
     int n = arr.size();
    
    // Step 1: Calculate the XOR of all elements in the array
    int X_total = 0;
    for (int num : arr) {
        X_total ^= num;
    }

    // Step 2: If the XOR of the entire array is not zero, return 0
    if (X_total != 0) {
        return 0;
    }

    // Step 3: If XOR is zero, find the number of valid splits
    // The number of ways to split non-empty subsets
    long long result = (modPow(2, n - 1, MOD) - 1 + MOD) % MOD;

    return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends