//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<long long int,int>mp;
        long long int prefix = 0;
        int len = 0 ;
        
        for(int r = 0 ; r < arr.size(); r++){
            prefix += arr[r];
            
            if(prefix == k) len = max(len,r+1);
            if(mp.find(prefix-k) != mp.end()) len = max(len,(r-mp[prefix-k]));
            if(mp.find(prefix) == mp.end())mp[prefix] = r;
        }
        return len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends