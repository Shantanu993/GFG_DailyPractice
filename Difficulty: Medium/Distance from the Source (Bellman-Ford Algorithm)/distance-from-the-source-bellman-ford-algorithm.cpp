//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dis(V, 10e7);
        dis[S]=0;
        
        for(int i=0; i<V-1; i++){
            for(auto e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                
                if(dis[u]!=10e7 && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                }
            }
        }
        
        vector<int> discpy(dis);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            if(discpy[u]!=10e7 && discpy[u]+w<discpy[v]){
                discpy[v]=discpy[u]+w;
            }
        }
        
        for(int i=0; i<V; i++){
            if(dis[i]!=discpy[i]){
                dis.clear();
                dis.push_back(-1);
                break;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends