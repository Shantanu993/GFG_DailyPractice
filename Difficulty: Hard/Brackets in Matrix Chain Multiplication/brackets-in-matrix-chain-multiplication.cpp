class Solution {
  public:
  vector<vector<int>>v;
  vector<vector<int>>split;
  
 
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n=arr.size();
        v.assign(n-1,vector<int>(n-1,0));
        split.assign(n-1,vector<int>(n-1,-1));
        
        for(int l=2; l<n; l++){
            for(int i=0; i<n-l; i++){
               int j=i+l-1;
                int mncost=1e9;
                for(int k=i; k<j; k++){
                    int cost=v[i][k]+v[k+1][j]+arr[i]*arr[k+1]*arr[j+1];
                    
                    if(cost<mncost){
                        mncost=cost;
                        split[i][j]=k;
                    }
                }
                v[i][j]=mncost;
            }
          
        }
         return parenthes(0,n-2); 
        
    }
    
     string parenthes(int i,int j){
            if(i==j) return string(1,'A'+i);
            int k = split[i][j];
            return "("+parenthes(i,k)+parenthes(k+1,j)+")";
        }
};