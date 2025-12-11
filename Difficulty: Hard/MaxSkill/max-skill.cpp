class Solution {
  public:
    int maxSkill(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>a(n+2,1);
        for(int i=0; i<n; i++) a[i+1]=arr[i];
        
        vector<vector<int>>v(n+2, vector<int>(n+2,0));
        
        for(int l=2; l<n+2; l++){
            for(int i=0; i<n+2-l; i++){
                int j=i+l;
                for(int k=i+1; k<j; k++){
                    v[i][j]= max(v[i][j], v[i][k]+v[k][j] + a[i]*a[k]*a[j]);
                }
            }
        }
        
        return v[0][n+1];
    }
};