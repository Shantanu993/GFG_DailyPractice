//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& g,pair<int,int>base,int i,int j,int n,int m ,vector<pair<int,int>>&p){
        if(i<0 || j<0 || i>=n ||j>=m||g[i][j]==0){
            return;
        }
        g[i][j]=0;
        p.push_back({i-base.first,j-base.second});
        dfs(g,base,i-1,j,n,m,p);
        dfs(g,base,i+1,j,n,m,p);
        dfs(g,base,i,j-1,n,m,p);
        dfs(g,base,i,j+1,n,m,p);
    }
    int countDistinctIslands(vector<vector<int>>& g) {
        // code here
        set<vector<pair<int,int>>>vp;
        int ans = 0,n= g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    vector<pair<int,int>>p;
                    p.clear();
                    dfs(g,{i,j},i,j,n,m,p);
                    vp.insert(p);
                }
            }
        }
        return vp.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends