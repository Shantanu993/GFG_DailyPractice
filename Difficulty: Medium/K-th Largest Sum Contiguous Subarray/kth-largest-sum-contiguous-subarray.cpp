//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // Function to find the kth largest element in the given array.
    int kthLargest(vector<int> &arr, int k) {
        int N = arr.size();
        vector<int> pre(N + 1);
        pre[0] = 0;
        pre[1] = arr[0];

        // Calculating prefix sum of the array.
        for (int i = 2; i <= N; i++) {
            pre[i] = pre[i - 1] + arr[i - 1];
        }

        // Creating a min-heap to store the k largest elements.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterating over all subarrays to find the k largest elements.
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                int x = pre[j] - pre[i - 1];

                // If heap size is less than k, add current element to heap.
                if (pq.size() < k) {
                    pq.push(x);
                }

                // If current element is larger than smallest element in heap,
                // replace smallest element with current element.
                else {
                    if (pq.top() < x) {
                        pq.pop();
                        pq.push(x);
                    }
                }
            }
        }

        // Returning the kth largest element.
        return pq.top();
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends