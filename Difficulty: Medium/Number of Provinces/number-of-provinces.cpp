//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<vector<int>>&graph,vector<int>&vis,int k){
        vis[node]=k;
        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(it,graph,vis,k);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>vis(V+1,0);
        vector<vector<int>>graph(V+1);
        for(int i=0;i<V;i++){
            for(int j=0;j<=i;j++){
                if(i!=j && adj[i][j]){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }
        int k=1;
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                dfs(i,graph,vis,k);
                k++;
            }
        }
        return k-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends