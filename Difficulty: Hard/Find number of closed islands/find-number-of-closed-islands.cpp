//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++


//User function Template for C++

class Solution {
    public:
    void convert(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        if(grid[i][j]==1)
        {
            grid[i][j]=0;
        }
        convert(i+1,j,grid);
        convert(i,j+1,grid);
        convert(i-1,j,grid);
        convert(i,j-1,grid);
        
    }
    int closedIslands(vector<vector<int>>& grid, int N, int M) {
        // Code here
        int count=0;
        for(int i=0;i<M;i++)
        {
            if(grid[0][i]==1)
            {
                convert(0,i,grid);
            }
            if(grid[N-1][i]==1)
            {
                convert(N-1,i,grid);
            }
        }
        for(int i=0;i<N;i++)
        {
            if(grid[i][0]==1)
            {
                convert(i,0,grid);
            }
            if(grid[i][M-1]==1)
            {
                convert(i,M-1,grid);
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                    convert(i,j,grid);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
	
	return 0;
	
}


// } Driver Code Ends