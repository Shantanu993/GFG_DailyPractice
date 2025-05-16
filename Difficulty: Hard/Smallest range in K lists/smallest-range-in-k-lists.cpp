//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Struct to represent elements in the heap
    struct Node {
        int val, row, col;

        bool operator>(const Node& other) const { return val > other.val; }
    };

    // Function to find the smallest range
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int n = arr.size();
        int k = arr[0].size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int maxVal = INT_MIN;

        // Push the first element of each list into the min-heap
        for (int i = 0; i < n; i++) {
            pq.push({arr[i][0], i, 0});
            maxVal = max(maxVal, arr[i][0]);
        }

        int minRange = INT_MAX, minEl, maxEl;

        while (true) {
            Node curr = pq.top();
            pq.pop();
            int minVal = curr.val;

            // Update range if better
            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
                minEl = minVal;
                maxEl = maxVal;
            }

            // If we've reached the end of a list, break
            if (curr.col + 1 == k)
                break;

            // Push next element from the same list
            int nextVal = arr[curr.row][curr.col + 1];
            pq.push({nextVal, curr.row, curr.col + 1});
            maxVal = max(maxVal, nextVal);
        }

        return {minEl, maxEl};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends