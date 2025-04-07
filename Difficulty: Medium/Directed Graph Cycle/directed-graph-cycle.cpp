//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool dfs(int node, vector<bool>& visit, unordered_map<int, vector<int>>& adj, vector<bool>& st){
        if(st[node])
            return true;
        if(visit[node])
           return false;
           
        visit[node] = true;
        st[node] = true;
        
        for(auto neighbor : adj[node]){
            if(dfs(neighbor, visit, adj, st)){
                return true;
            }
        }
        st[node] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visit(V, false);
        vector<bool> st(V, false);
        
        for(int i=0; i<V; i++){
            if(!visit[i] && dfs(i, visit, adj, st)){
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends