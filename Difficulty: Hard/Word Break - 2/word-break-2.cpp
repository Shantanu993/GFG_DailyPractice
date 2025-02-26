//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    
    //string is taken by reference
    void solve(string &s,vector<string>& dict,int idx,vector<string>&ans,vector<string>&temp){
       if(idx==s.size()){
           string god;
           for(int i=0;i<temp.size();i++){
               god+=temp[i];
               if(i!=temp.size()-1){
                   god+=" ";
               }
           }
           ans.push_back(god);
           return;
       }
       string word;
       for(int i=idx;i<s.size();i++){
           word+=s[i];
            if(find(dict.begin(),dict.end(),word)!=dict.end()){
                temp.push_back(word);
                solve(s,dict,i+1,ans,temp);
                temp.pop_back();
            }
        }
  }
    vector<string> wordBreak(vector<string>& dict, string s) {
        // code here
        vector<string>ans;
        vector<string>temp;
        solve(s,dict,0,ans,temp);
        return ans;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict;
        string s;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s) {
            dict.push_back(s);
        }
        cin >> s;
        cin.ignore();
        Solution ob;
        vector<string> ans = ob.wordBreak(dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends