//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        // Check if out of bounds
        if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size())
            return 0;
        
        // If last row, return the value
        if(i == mat.size()-1)
            return mat[i][j];
        
        // If already computed, return memoized result
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // Recursive computation with careful path finding
        int down = solve(i+1, j, mat, dp);
        int downLeft = solve(i+1, j-1, mat, dp);
        int downRight = solve(i+1, j+1, mat, dp);
        
        // Find maximum path and add current cell's value
        int maxPath = mat[i][j] + max({down, downLeft, downRight});
        
        // Memoize and return
        return dp[i][j] = maxPath;
    }
    
    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        // Initialize DP table
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // Find maximum path starting from each column in first row
        int maxPathSum = 0;
        for(int j = 0; j < m; j++){
            maxPathSum = max(maxPathSum, solve(0, j, mat, dp));
        }
       
        return maxPathSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends