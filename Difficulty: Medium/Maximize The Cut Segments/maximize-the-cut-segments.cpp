//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
int rec(int n, int x, int y, int z, vector<int>& dp) {
    if (n == 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    int xCut = -1e9;
    int yCut = -1e9;
    int zCut = -1e9;

    if (x <= n) {
        xCut = 1 + rec(n - x, x, y, z, dp);
    }
    if (y <= n) {
        yCut = 1 + rec(n - y, x, y, z, dp);
    }
    if (z <= n) {
        zCut = 1 + rec(n - z, x, y, z, dp);
    }

    return dp[n] = max({xCut, yCut, zCut});
}

int maximizeTheCuts(int n, int x, int y, int z) {
    vector<int> dp(n + 1, -1);
int ans= rec(n, x, y, z, dp);
if(ans<0)return 0;
return ans;
}
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends