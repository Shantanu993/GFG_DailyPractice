//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int edit(string s, string t, vector<vector<int>>&output){
      int m=s.length();
      int n=t.length();
     if(s.length()==0||t.length()==0){
            return max(s.size(),t.size());
        }
        if(output[m][n]!=-1){
            return output[m][n];
        }
        int ans;
        if(s[0]==t[0]){
            ans=edit(s.substr(1),t.substr(1),output);
        }
        else{
            int Delete = 1+edit(s,t.substr(1),output);
            int insert= 1+edit(s.substr(1),t,output);
            int replace = 1+edit(s.substr(1),t.substr(1),output);
            ans=min(Delete,min(insert,replace));
            // return min(Delete,min(insert,replace));   
        }  
          return output[m][n]=ans;
          
  }
    int editDistance(string s, string t) {
       
        int m=s.size();
        int n=t.size();
        vector<vector<int>> output(m+1,vector<int>(n+1,-1));
        return edit(s,t,output);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends