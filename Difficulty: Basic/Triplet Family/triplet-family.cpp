//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
         int n = arr.size();
    // Sort the array
    std::sort(arr.begin(), arr.end());

    // Loop through each element
    for (int i = n - 1; i >= 0; i--) {
        int left = 0;
        int right = i - 1;

        // Use two pointers to find if there exists a pair that sums to arr[i]
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) {
                // std::cout << "Triplet found: " << arr[left] << ", " << arr[right] << ", " << arr[i] << std::endl;
                return true;
            } else if (sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }
    }

    // If no triplet found
    return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends