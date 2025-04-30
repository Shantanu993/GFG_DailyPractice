//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i]==0) q.push(i);
        }
    
        vector<int> res;
    
        while(q.size()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto x : adj[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
    
        if(res.size()!=n) return {};
        return res; // tc:0(e)+(v)
                    // sc:0(2n)
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<int> adj[]) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u, v});
        }

        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);

        Solution obj;
        vector<int> res = obj.findOrder(n, prerequisites);

        if (check(n, res, adj))
            cout << "true" << endl;

        else
            cout << "false\n";
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends