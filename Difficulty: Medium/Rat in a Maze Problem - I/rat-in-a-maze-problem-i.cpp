//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void charm(vector<vector<int>>&grid,string path,int i,int j,vector<string>&ans,int x[],int y[],char dir[],vector<vector<int>>&vis)
    {
        if(i==grid.size()-1 and j==grid[0].size()-1)
        {
            ans.push_back(path);
            return;
        }
        else
        {
            vis[i][j]=1;
            for(int k=0;k<4;k++)
            {
                if(i+x[k]<0 or i+x[k]>grid.size()-1 or j+y[k]<0 or j+y[k]>grid[0].size()-1 or grid[i+x[k]][j+y[k]]==0 or vis[i+x[k]][j+y[k]]==1)
                continue;
                else
                {
                    path+=dir[k];
                    charm(grid,path,i+x[k],j+y[k],ans,x,y,dir,vis);
                    path.pop_back();
                }
            }
            vis[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Your code goes here
        string path="";
        
        vector<string>ans;
        if(mat[mat.size()-1][mat[0].size()-1]==0 or mat[0][0]==0)
        return ans;
        
        int x[4]={0,0,-1,1};
        int y[4]={-1,1,0,0};
        char dir[4]={'L','R','U','D'};
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        charm(mat,path,0,0,ans,x,y,dir,vis);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends