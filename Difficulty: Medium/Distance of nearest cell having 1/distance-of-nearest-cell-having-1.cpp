//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int i,j,n=grid.size(),m=grid[0].size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue <pair<pair<int,int>,int>> q;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                     q.push({{i,j},0});
                     visited[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            mat[r][c]=steps;
            for(i=-1;i<=1;i++)
            {
                for(j=-1;j<=1;j++)
                {
                    if(i==0 || j==0)
                    {
                        int nr=r+i , nc=c+j;
                        if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc])
                        {
                            visited[nr][nc]=1;
                            q.push( {{nr,nc},steps+1} );
                        }
                    }
                }
            }
            
        }
        return mat;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends