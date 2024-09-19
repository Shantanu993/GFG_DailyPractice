//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        stack<string>s;
        int n=str.size();
        int i=0,j=0;
        string ans="";
        while(i<n && j<n)
        {
            if(j==n-1)
            {
                string x= str.substr(i,(j-i)+1);
                s.push(x);
                i=j+1; 
            }
            else if(str[j]=='.')
            {
                string x= str.substr(i,(j-i));
                s.push(x);
                i=j+1;
            }
            j++;
        }
        while(!s.empty())
        {
            string x= s.top();
            ans+=x;
            s.pop();
            if(s.size()>0)
            ans.push_back('.');
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends