//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  vector<vector<bool>>dp;
	int minDifference(int arr[], int n)  { 
	 	   // we have to mini minimize the expression (range-2s1)
	   //first we to find all possible value for s1 by arr elements
	   //1. find the range value
	   int range = 0;
	   vector<int>PossibleSum;
	   for(int i = 0; i<n ;i++){
	       range += arr[i];
	   }
	   //2. resize the dp
	   dp.resize(n+1,vector<bool>(range+1));
	   //initialize the dp
	   
	   for(int j = 1;j<range+1;j++){
	       dp[0][j] = false;
	   }
	   for(int i = 0 ;i<n+1;i++){
	       dp[i][0] = true;
	   }

	   for(int i = 1;i<n+1;i++){
	       for(int j=0;j<range+1;j++){
	          if(arr[i-1]<=j){
	               dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	          }
	          else{
	              dp[i][j] = dp[i-1][j];
	          }
	       }
	   }
	   
	   
	   //find all sum possible from dp last row
	   for(int j = 0 ;j<range+1;j++){
	       if(dp[n][j]==1){
	           PossibleSum.push_back(j);
	       }
	   }
	   
	   int ans = INT_MAX;
	   for(int i = 0;i<=PossibleSum.size()/2;i++){
	       ans = min(ans,abs(range-( 2*PossibleSum[i])));
	   }
	   
	  return ans;
	   
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends