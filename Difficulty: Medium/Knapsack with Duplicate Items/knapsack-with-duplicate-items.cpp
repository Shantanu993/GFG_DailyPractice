//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int help(int ind, int W, int weight[], int val[],vector<vector<int>>&dp) {
  if (ind == 0) {
    //if we have W=8 and last item weight as 3 , val=10 so at that case we can take 3 2 times so 10+10=20
    //8/3=2*10;
    return (W/weight[0])*val[0];
  }
  if(dp[ind][W]!=-1)return dp[ind][W];

  int not_take=help(ind-1,W,weight,val,dp);
  int take=INT_MIN;
  if (weight[ind]<= W) {
  take=val[ind]+help(ind,W-weight[ind],weight,val,dp);
  } 
  return dp[ind][W]=max(take,not_take);
}

    int knapSack(int n, int W, int val[], int wt[])
    {
       	vector<vector<int>>dp(n,vector<int>(W+1,-1));
	   return help(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends