class Solution {
  public:
    virtual int minCost(vector<vector<int>>& houses) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({0, 0});
      
      long long ans=0LL;
      auto manDis = [&](vector<int> &a, vector<int> &b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);  
      };
      
      int n=houses.size();
      vector<bool> visited(n, false);
      
      while(!pq.empty()){
        auto [dis, i]=pq.top(); pq.pop();
        if(visited[i]) continue;
        
        visited[i]=true;
        ans += (1LL*dis);
        
        for(int j=0; j<n; j++){
          if(!visited[j]){
            int d=manDis(houses[i], houses[j]);
            pq.push({d, j});
          }    
        }
        
      }
      
      return (int)ans;
      
    }
};