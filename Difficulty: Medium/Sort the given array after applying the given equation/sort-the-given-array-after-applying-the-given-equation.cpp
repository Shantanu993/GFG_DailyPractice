//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to apply quadratic transformation
    int evaluate(int x, int A, int B, int C) { return A * x * x + B * x + C; }

    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> newArr(n);

        int left = 0, right = n - 1;
        int index = (A >= 0) ? n - 1 : 0;

        // Two-pointer approach to fill newArr
        // from end or start
        while (left <= right) {
            int leftVal = evaluate(arr[left], A, B, C);
            int rightVal = evaluate(arr[right], A, B, C);

            if (A >= 0) {

                // Fill from end
                if (leftVal > rightVal) {
                    newArr[index--] = leftVal;
                    left++;
                } else {
                    newArr[index--] = rightVal;
                    right--;
                }
            } else {

                // Fill from start
                if (leftVal < rightVal) {
                    newArr[index++] = leftVal;
                    left++;
                } else {
                    newArr[index++] = rightVal;
                    right--;
                }
            }
        }

        return newArr;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends