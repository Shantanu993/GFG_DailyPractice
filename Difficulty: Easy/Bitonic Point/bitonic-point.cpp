//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int n = arr.size();
        
        if(n==0 || arr[0]>arr[1]) return arr[0];
        if(arr[n-1]>arr[n-2]) return arr[n-1];
        
        for(int i=1; i<n-1; i++){
            if(arr[i]>arr[i-1] && arr[i+1]<arr[i]) return arr[i];
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends