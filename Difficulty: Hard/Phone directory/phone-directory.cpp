//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int m = s.length();
        vector<vector<string>> ans(m,vector<string>());
        //important sorting
        sort(contact,contact+n);
        for(int i=0; i<n; i++)
        {
            string word = contact[i];
            
            if(i > 0 && word == contact[i-1])
                continue;
                
            int j = 0;
            while(j < m && j < word.length() && word[j] == s[j])
            {
                ans[j].push_back(word);
                j++;
            }
        }
        
        for(int k = 0; k<m; k++){
            if(ans[k].empty())
                ans[k].push_back("0");
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends