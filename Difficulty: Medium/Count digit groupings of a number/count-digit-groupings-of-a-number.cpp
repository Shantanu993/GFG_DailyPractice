//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	
	// Recursive Approach
	int TotalCount_Recursive(string &str , int start_index , int prev_sum)
	{
	    int n = str.length();
	    if(start_index == n)
	    {
	        return 1;
	    }
	    
	    int next_sum = 0;
	    int ans = 0;
	    for(int i = start_index ; i < n ; i++)
	    {
	        next_sum += (str[i]-'0');
	        if(next_sum >= prev_sum)
	        {
	            ans += TotalCount_Recursive(str , i + 1 , next_sum);
	        }
	    }
	    return ans;
	}
	
	int TotalCount_Memo(string &str , int start_index , int prev_sum , vector<vector<int>> &dp)
	{
	    int n = str.length();
	    if(start_index == n)
	    {
	        return 1;
	    }
	    if(dp[start_index][prev_sum]!=-1)
	    {
	        return dp[start_index][prev_sum];
	    }
	    int next_sum = 0;
	    int ans = 0;
	    for(int i = start_index ; i < n ; i++)
	    {
	        next_sum += (str[i]-'0');
	        if(next_sum >= prev_sum)
	        {
	            ans += TotalCount_Memo(str , i + 1 , next_sum , dp);
	        }
	    }
	    return dp[start_index][prev_sum] = ans;
	}
	int TotalCount(string str)
	{
	    // Code here
	    vector<vector<int>> dp(101 , vector<int>(905, -1));
	    
	    //return TotalCount_Recursive(str , 0 , 0);
	    return TotalCount_Memo(str , 0 , 0 , dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends