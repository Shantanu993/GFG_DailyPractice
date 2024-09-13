//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings


class Solution
{
public:
int helper(int i,string s,set<string>&st)
{
    int n=st.size();
    string temp="";
    if(i==s.size())   ////string segmented when reach last index
    return 1;
    for(int k=i;k<s.size();k++)
    {
        temp+=s[k];
        if(st.find(temp)!=st.end())
        {
            if(helper(k+1,s,st))
            return 1;
        }
        
    }
    return 0;
}
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        set<string>st;
        for(auto it:dictionary)
        {
            st.insert(it);
        }
        return helper(0,s,st);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends