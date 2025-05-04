//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_set<char> unique(str.begin(), str.end());
        int n=str.size();
        int total=unique.size();
        int start=0, cnt=0;
        int len=INT_MAX;
        unordered_map<char, int> mpp;
        for(int end=0; end<n; end++){
            mpp[str[end]]++;
            if(mpp[str[end]]==1) cnt++;
            while(cnt==total){
                len=min(len, end-start+1);
                mpp[str[start]]--;
                if(mpp[str[start]]==0) cnt--;
                start++;
            }
        }
        return len;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends