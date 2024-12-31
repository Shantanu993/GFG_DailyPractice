//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    bool solve(string &s, string &p,int i,int j,vector<vector<int>>&dp){
     
     // base case
    if(i>=s.size()){
    bool chk=1;

    for(int idx =j;idx<p.size();idx++){
    if(p[idx]!='*')
    {
    chk=0;
    break;
    }
    }

    if(chk || j>=p.size()) 
    return 1;

    }
   
    
    if(i>=s.size())
    return 0;

    if(j>=p.size())
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];
    
    bool isposs=0;

    if(s[i]==p[j] || p[j]=='?'){
    isposs|= solve(s,p,i+1,j+1,dp);
    }

   else if(p[j]=='*'){
    isposs|= solve(s,p,i,j+1,dp);
    isposs|= solve(s,p,i+1,j,dp);
    }

    else isposs=0;


    return dp[i][j]=isposs;

    }
    
    public:
    bool match(string wild, string pattern)
    {
        
    int len2=wild.size();
    int len1=pattern.size();
    vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
    
  return solve(pattern,wild,0,0,dp);
  
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends