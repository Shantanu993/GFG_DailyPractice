//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++


class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> maze, int X, int Y) {
        if(maze[X][Y]==0 or maze[0][0]==0) return -1;
        queue<vector<int>> q;
        vector<vector<bool>> visit(N,vector<bool>(M,false));
        vector<int> direcI={0,0,1,-1};
        vector<int> direcJ={-1,1,0,0};
        q.push({0,0,0});//i j dist ;
        visit[0][0]=true;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int curi=cur[0];
            int curj=cur[1];
            int dist=cur[2];
            // cout<<curi<<' '<<curj<<':'<<X<<' '<<Y<<'\n';
            if(curi==X and curj==Y) return dist ;
            for(int i=0;i<4;i++){
                int ni=curi+direcI[i];
                int nj=curj+direcJ[i];
                if(ni>=0 and nj>=0 and ni<N and nj<M and maze[ni][nj] and !visit[ni][nj]){
                    q.push({ni,nj,dist+1});
                    visit[ni][nj]=true;
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends