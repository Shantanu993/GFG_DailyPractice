//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &nums) {
        int result = 0;
        int mask = 0;
        set<int> prefix_set;
        
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            prefix_set.clear();
            
            for (int num : nums) {
                prefix_set.insert(num & mask);
            }
            
            int temp = result | (1 << i);
            
            for (int prefix : prefix_set) {
                if (prefix_set.count(temp ^ prefix)) {
                    result = temp;
                    break;
                }
            }
        }
        
        return result;
        
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends