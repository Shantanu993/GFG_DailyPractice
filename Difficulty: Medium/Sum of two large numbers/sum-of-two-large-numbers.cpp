//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    string findSum(string s1, string s2) {
        // Before proceeding further, make sure length
        // of s2 is larger.
        if (s1.length() > s2.length())
            swap(s1, s2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = s1.length(), n2 = s2.length();
        int diff = n2 - n1;

        // Initially take carry zero
        int carry = 0;

        // Traverse from end of both strings
        for (int i = n1 - 1; i >= 0; i--) {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((s1[i] - '0') + (s2[i + diff] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining digits of s2[]
        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = ((s2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining carry
        if (carry)
            str.push_back(carry + '0');

        // reverse resultant string
        reverse(str.begin(), str.end());

        int i = 0, n = str.size();
        while (i < n and str[i] == '0')
            i++;

        if (i == n)
            return "0";

        return str.substr(i, (int)str.size() - i + 1);
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends