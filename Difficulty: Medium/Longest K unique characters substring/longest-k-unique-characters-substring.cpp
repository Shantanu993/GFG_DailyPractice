//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxlen = -1;
        map <char, int> mpp;
        
        
        while (r < n)
        {
            mpp[s[r]]++;
            
            while (mpp.size() > k)
            {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                {
                    mpp.erase(s[l]);
                }
                l++;
            }
            
            if (mpp.size() == k)
            {
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        
        return maxlen;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends