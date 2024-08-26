//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int solve(int* arr, int ind,int prev_index,vector<vector<int>>&dp){
        if(ind<0){
            return 0;
        }
        if(dp[ind][prev_index+1] != -1) return dp[ind][prev_index+1];
        int not_pick = 0+ solve(arr,ind-1,prev_index,dp);
        int pick = 0;
        if(prev_index == -1 || arr[ind] <arr[prev_index]){
            pick = arr[ind]+solve(arr,ind-1,ind,dp);
        }
        return dp[ind][prev_index+1] = max(not_pick,pick);
    }

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return solve(arr,n-1,-1,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends