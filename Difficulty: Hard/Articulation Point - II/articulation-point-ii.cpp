class Solution {
  public:
    int timestamp=0;
    virtual void dfs(int i, int par, vector<int> &timer, vector<int> &low, vector<int> &okk, vector<bool> &visited, vector<vector<int>> &adj){
      visited[i]=true;
      timer[i]=timestamp;
      low[i]=timestamp;
      timestamp++;
      
      int child=0;
      for(auto x: adj[i]){
        if(x==par) continue;
        if(!visited[x]){
          child++;
          dfs(x, i, timer, low, okk, visited, adj);
          low[i]=min(low[i], low[x]);
          if(low[x]>=timer[i] && par!=-1) okk[i]=1;
        }
        else low[i]=min(low[i], timer[x]);
      }
      if(child>1 && par==-1) okk[i]=1;
      return;
    }
    
    virtual vector<int> articulationPoints(int V, vector<vector<int>>& edges){
      vector<vector<int>> adj(V);
      for(auto x: edges){
        adj[x[0]].push_back(x[1]);  
        adj[x[1]].push_back(x[0]);  
      }
      
      vector<int> timer(V, -1);
      vector<int> low(V, -1);
      vector<int> okk(V, -1);
      vector<bool> visited(V, false);
      
      for(int i=0; i<V; i++){
        if(!visited[i]){
          dfs(i, -1, timer, low, okk, visited, adj);    
        }  
      }
      
      vector<int> ans;
      for(int i=0; i<V; i++){
        if(okk[i]==1) ans.push_back(i);  
      }
      if(ans.empty()) return {-1};
      
      return ans;
    }
};