class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
       int n=mat.size(),m=mat[0].size();
       vector<int> ans;
       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){
               mat[i][j]+=mat[i-1][j];
           }
       }
       for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
               mat[i][j]+=mat[i][j-1];
           }
       }
       for(auto q:queries){
           int r1=q[0],c1=q[1],r2=q[2],c2=q[3];
           int total=mat[r2][c2];
           int minir=min(r1,r2)-1;
           int minic=min(c1,c2)-1;
           int maxir=max(r1,r2);
           int maxic=max(c1,c2);
           if(minir!=-1){
               total-=mat[minir][maxic];
           }
           if(minic!=-1){
               total-=mat[maxir][minic];
           }
           if(minic!=-1 && minir!=-1){
               total+=mat[minir][minic];
           }
           ans.push_back(total);
       }
       return ans;
    }
};
