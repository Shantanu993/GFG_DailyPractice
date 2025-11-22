class DSU{
  private:
    vector<int> rank;
    vector<int> parent;
  public:
    DSU(int V){
        rank.resize(V);
        parent.resize(V);
        for(int i = 0;i<V;i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int GetNumSets(){
        int cnt = 0;
        for(int i = 0;i<parent.size();i++){
            if(i == parent[i]){
                cnt++;
            }
        }
        return cnt;
    }
    int FindParent(int x){
        if(parent[x]==x)return x;
        return parent[x] = FindParent(parent[x]);
    }
    void JoinInSet(int a, int b){
        int pa = FindParent(a);
        int pb = FindParent(b);
        
        if(rank[pa]<=rank[pb]){
            parent[pa] = pb;
            if(rank[pa]==rank[pb])rank[pb]++;
        }
        else{
            parent[pb] = pa;
        }
    }
};
class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        int extra = 0;
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            int pu = dsu.FindParent(u);
            int pv = dsu.FindParent(v);
            
            if(pu == pv){
                extra++;
            }
            else{
                dsu.JoinInSet(u, v);
            }
        }
        int num_comp = dsu.GetNumSets();
        if(num_comp-1>extra)return -1;
        return num_comp-1;
    }
};