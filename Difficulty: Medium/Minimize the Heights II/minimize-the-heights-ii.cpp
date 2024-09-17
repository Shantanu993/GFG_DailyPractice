//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return 0; // No difference if there's only one element

        sort(arr.begin(), arr.end());

        // Initial difference between max and min
        int diff = arr[n-1] - arr[0];
        
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;

        for (int i = 1; i < n; i++) {
            // If subtracting k makes the element negative, skip
            if (arr[i] - k < 0) continue;
            
            // Update the new smallest and largest
            int min_element = min(smallest, arr[i] - k);
            int max_element = max(largest, arr[i-1] + k);
            
            // Minimize the difference
            diff = min(diff, max_element - min_element);
        }

        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends