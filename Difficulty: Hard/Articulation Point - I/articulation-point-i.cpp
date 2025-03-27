//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
class Solution {
    
     void dfs(int u, vector<int> adj[], vector<int>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<int>& isAP, int& time) {
        visited[u] = 1;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (auto v : adj[u]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v, adj, visited, disc, low, parent, isAP, time);
                
                // Check if the subtree rooted at v has a connection to one of the ancestors of u
                low[u] = min(low[u], low[v]);

                // u is an articulation point in two cases:
                // Case 1: u is root of DFS tree and has more than one child
                if (parent[u] == -1 && children > 1)
                    isAP[u] = 1;

                // Case 2: u is not root and low value of one of its child is more than discovery value of u
                if (parent[u] != -1 && low[v] >= disc[u])
                    isAP[u] = 1;

            } else if (v != parent[u]) {
                // Update low value of u for parent function calls
                low[u] = min(low[u], disc[v]);
            }
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> visited(V, 0), disc(V), low(V), parent(V, -1), isAP(V, 0);
        int time = 0;

        // Perform DFS from each node to handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, disc, low, parent, isAP, time);
            }
        }

        // Collect the articulation points
        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                res.push_back(i);
            }
        }

        if (res.empty()) return {-1};  // If no articulation points found, return -1
        return res;
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends