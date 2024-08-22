//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
     void dfs(int r ,int c , vector<vector<int>>&vis,vector<vector<char>>& grid){
        
        vis[r][c] = 1;
        
         int n = grid.size();
         int m = grid[0].size();
     
            // traverse the neighbour nodes
            for(int dr=-1; dr <= 1; dr++){
                for(int dc = -1; dc<=1 ; dc++){
                    
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nr < n && nc >=0 && nc < m 
                         && grid[nr][nc] =='1' && !vis[nr][nc]){
                      
             
                      dfs(nr,nc,vis,grid);
                  }
                }
            }
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
          int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m  ; j++){
                
                if(!vis[i][j] && grid[i][j] =='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends