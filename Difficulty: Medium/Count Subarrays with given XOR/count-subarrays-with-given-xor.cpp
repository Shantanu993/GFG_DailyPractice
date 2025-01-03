//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
         int res = 0; 

    // Create hash map that stores number of prefix arrays
    // corresponding to a XOR value
    unordered_map<int, int> mp;
  
      int prefXOR = 0;
  
    for (int val : arr) {
      
        // Find XOR of current prefix
        prefXOR ^= val;

        // If prefXOR ^ k exist in mp then there is a subarray 
          // ending at i with XOR equal to k
        res = res + mp[prefXOR ^ k];

        // If this prefix subarray has XOR equal to k
        if (prefXOR == k)
            res++;

        // Add the XOR of this subarray to the map
        mp[prefXOR]++;
    }

    // Return total count of subarrays having XOR of
    // elements as given value k
    return res;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends