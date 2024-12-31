//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
void dfs(int row , int col , vector<vector<char>>&mat , vector<vector<int>>&vis,int drow[],int dcol[]){
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
            dfs(nrow,ncol,mat,vis,drow,dcol);
        }

    }

}
class Solution {
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
         int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        //traverse first row and last row 
        for(int j=0;j<col;j++){
            //first row
            if(!vis[0][j] && mat[0][j]=='O'){
                //call dfs on this
                dfs(0,j,mat,vis,drow,dcol);


            }
            //last row
            if(!vis[row-1][j] && mat[row-1][j]=='O'){
                //call dfs on this
                dfs(row-1,j,mat,vis,drow,dcol);

            }
        }


        // traverse along first column and last column
        for(int i=0;i<row;i++){
            //first column
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,mat,vis,drow,dcol);
            }
            //last column
            if(!vis[i][col-1] && mat[i][col-1]=='O'){
                dfs(i,col-1,mat,vis,drow,dcol);
            }
        }
// traverse along all matrix and change the 0s with X if they are not lying on the boundary

for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){

        if(!vis[i][j] && mat[i][j]=='O'){
            mat[i][j] = 'X';
        }
    }
}
return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends