//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int minOperations(string s, string t) 
	{ 
	    // Your code goes here
	    
	    int n=s.size(),m=t.size();
	    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
	    
	    function<int(int,int)> solve= [&](int i,int j)->int
	    {
	        if(j==0) return i;
	        if(i==0) return j;
	        if(dp[i][j]!=-1) return dp[i][j];
	        if(s[i-1]==t[j-1]) return dp[i][j]=solve(i-1,j-1);
	        else{
	            return dp[i][j]=min(1+solve(i-1,j),1+solve(i,j-1));
	        }
	    };
	    
	    return solve(n,m);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends