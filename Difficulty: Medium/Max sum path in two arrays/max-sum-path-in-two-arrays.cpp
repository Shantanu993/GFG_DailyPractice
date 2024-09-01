//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &ar1, vector<int> &ar2) {
        // Code here
        int n = ar2.size(), m = ar1.size();
        // initialize indexes for ar1[] and ar2[]
    int i = 0, j = 0;

    // Initialize result and current sum through ar1[] and
    // ar2[].
    int result = 0, sum1 = 0, sum2 = 0;

    // Below 3 loops are similar to merge in merge sort
    while (i < m && j < n) {
        // Add elements of ar1[] to sum1
        if (ar1[i] < ar2[j])
            sum1 += ar1[i++];

        // Add elements of ar2[] to sum2
        else if (ar1[i] > ar2[j])
            sum2 += ar2[j++];

        else // we reached a common point
        {
            // Take the maximum of two sums and add to
            // result
            // Also add the common element of array, once
            result += max(sum1, sum2) + ar1[i];

            // Update sum1 and sum2 for elements after this
            // intersection point
            sum1 = 0;
            sum2 = 0;

            // update i and j to move to next element of
            // each array
            i++;
            j++;
        }
    }

    // Add remaining elements of ar1[]
    while (i < m)
        sum1 += ar1[i++];

    // Add remaining elements of ar2[]
    while (j < n)
        sum2 += ar2[j++];

    // Add maximum of two sums of remaining elements
    result += max(sum1, sum2);

    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends