//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to keep the maximum result
    void match(string& curr, string& result) {

        // If current number is larger, update result
        if (curr > result) {
            result = curr;
        }
    }

    // Function to set highest possible digits at given index.
    void setDigit(string& str, int index, string& res, int k) {
        // base case
        if (k == 0 || index == str.size() - 1) {
            match(str, res);
            return;
        }

        int maxDigit = 0;

        // finding maximum digit for placing at given index.
        for (int i = index; i < str.size(); i++)
            maxDigit = max(maxDigit, str[i] - '0');

        // swapping isn't needed in this case.
        if (str[index] - '0' == maxDigit) {
            setDigit(str, index + 1, res, k);
            return;
        }

        for (int i = index + 1; i < str.size(); i++) {
            // if max digit is found at current index.
            if (str[i] - '0' == maxDigit) {
                // swapping to get the maximum digit at required index.
                swap(str[index], str[i]);

                // calling recursive function to set the next digit.
                setDigit(str, index + 1, res, k - 1);

                // backtracking
                swap(str[index], str[i]);
            }
        }
    }

    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        string res = s;
        setDigit(s, 0, res, k);

        // returning the result.
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends