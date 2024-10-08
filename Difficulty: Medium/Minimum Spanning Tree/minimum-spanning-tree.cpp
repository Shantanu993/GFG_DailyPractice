//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>visited(V,-1);
        pq.push({0,0});
        int mst=0;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            
            if(visited[node]==1) continue;
            visited[node]=1;
            mst+=wt;
            
            for(auto it : adj[node]){
                int adj_wt=it[1];
                int adj_node=it[0];
                
                if(visited[adj_node]==-1){
                    pq.push({adj_wt, adj_node});
                }
            }
        }
        return mst;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends