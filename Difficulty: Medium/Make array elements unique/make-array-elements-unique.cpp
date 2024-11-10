//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
    
       int cost = 0;
    sort(arr.begin(),arr.end());
    // Traverse the sorted array, making each element unique by incrementing if necessary
    for (int i = 1; i < arr.size(); ++i) {
        // If arr[i] is not unique (i.e., less than or equal to the previous element)
        if (arr[i] <= arr[i - 1]) {
            // Calculate the increment needed to make arr[i] one more than arr[i - 1]
            int increment = arr[i - 1] - arr[i] + 1;
            arr[i] += increment;
            cost += increment;  // Add the increment to the total cost
        }
    }
    
    return cost;
       
          
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends