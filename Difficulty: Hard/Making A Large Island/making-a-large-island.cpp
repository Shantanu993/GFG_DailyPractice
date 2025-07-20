class DisjointSet{
    public:
        vector<int>parent,size;
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i = 0;i<n;i++) parent[i] = i;
        }
        
        int findulPar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findulPar(parent[node]);
        }
        
        void unionBysize(int u,int v){
            int ulp_u = findulPar(u);
            int ulp_v = findulPar(v);
            if(ulp_u==ulp_v) return;
            if(size[ulp_v]>size[ulp_u]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
        
};
class Solution {
    private:
        bool isValid(int r,int c,int n){
            return r>=0 && r<n && c>=0 && c<n;
        }
  public:
  
    int largestIsland(vector<vector<int>>& grid) {
        // Your code goes here.
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int di[] = {-1,0,0,+1};
        int dj[] = {0,-1,+1,0};
        
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col] == 0) continue;
                for(int ind = 0;ind<4;ind++){
                    int nrow = row+di[ind];
                    int ncol = col+dj[ind];
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol] == 1){
                            int node = row*n+col;
                            int adjNode = nrow*n+ncol;
                            if(ds.findulPar(node)!=ds.findulPar(adjNode)){
                                ds.unionBysize(node,adjNode);
                            }
                        }
                    }
                }
                
            }
        }
        
        int maxSize = *max_element(ds.size.begin(),ds.size.end());
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col] == 1) continue;
                set<int>st;
                for(int ind= 0;ind<4;ind++){
                    int nrow = row+di[ind];
                    int ncol = col+dj[ind];
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol] == 1){
                            
                            int adjNode = nrow*n+ncol;
                            
                            st.insert(ds.findulPar(adjNode));
                        }
                    }
                }
                int ls = 1;
                for(auto it:st){
                    ls+=ds.size[it];
                }
                maxSize = max(maxSize,ls);
            }
        }
        
        return maxSize;
        
        
    }};