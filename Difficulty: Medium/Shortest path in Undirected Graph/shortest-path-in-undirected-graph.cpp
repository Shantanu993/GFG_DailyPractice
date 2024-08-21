//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        for (auto it : edges) {
            int u = it[0], v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int, int>> q;
        vector<int> dist(N, 1e9);
        
        q.push({0, src});
        dist[src] = 0;
        
        while (!q.empty()) {
            
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();
            
            if (dist[node] < dis)
                continue;
            
            
            for (auto it : adj[node]) {
                
                if (dist[it] > dis + 1) {
                    
                    dist[it] = dis + 1;
                    q.push({dist[it], it});
                }
            }
        }
        
        for (auto &it : dist)
            if (it == 1e9) it = -1;
        
        return dist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends