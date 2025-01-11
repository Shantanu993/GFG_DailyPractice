//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n=s.length(),ans=0;
        vector<int>v(26,0);
        for(int j=0,i=0;j<s.length();j++){
            if(v[s[j]-'a']>0){
                i=max(v[s[j]-'a'],i);
            }
            ans=max(ans,j-i+1);
            v[s[j]-'a']=j+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends