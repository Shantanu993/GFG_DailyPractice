//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string rem(string &s)
    {
        if (s.empty()) return s;
        int n = s.size();
        string temp = "";
        bool istrue = false;
        for (int i = 0; i < n; i++)
        {
            if ((i - 1 >= 0 and s[i - 1] == s[i]) or (i + 1 < n and s[i + 1] == s[i]))
            istrue = true;
            else temp.push_back(s[i]);
        }
        if (!istrue) return s;
        else return rem(temp);
    }
    string rremove(string s)
    {
        return rem(s);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends