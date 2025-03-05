//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int longestStringChain(vector<string>& str){
        // Code here
        int ans=1;
        vector<unordered_set<string>> arr(11);
        unordered_map<string, int> mp;
        
        for(auto &s:str){
            if(s.size()==1) mp[s]=1;
            arr[s.size()].insert(s);
        }
        
        for(int i=2;i<=10;i++){
            for(auto &s:arr[i]){
                mp[s]=1;
                for(int j=0;j<s.size();j++){
                    string str1=s.substr(0,j) + s.substr(j+1);
                    if(arr[i-1].count(str1)){
                        mp[s]=max(mp[s],1+mp[str1]);
                    }
                    ans=max(ans,mp[s]);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends