//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution

{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist (V, INT_MAX);
        
        set<pair<int, int> > st;
        
        st.insert(make_pair(0, S));
        
        dist[S] = 0;
        
        while(!st.empty()){
            auto node = *(st.begin());
            st.erase(st.begin());
            int distance = node.first;
            int topnode = node.second;
            for(auto it : adj[topnode]){
                if(distance + it[1] < dist[it[0]]){
                    auto record = st.find(make_pair(dist[it[0]], it[0]));
                    if(record!= st.end()){
                        st.erase(record);
                    }
                    
                    dist[it[0]] = distance + it[1];
                    st.insert({dist[it[0]], it[0]});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends