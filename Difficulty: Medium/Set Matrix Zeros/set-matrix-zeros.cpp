class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        //row and colun
        vector<pair<int, int>> vec;
        for (int i=0; i< mat.size(); i++){
            for (int j=0; j< mat[i].size(); j++){
                if(mat[i][j]==0){
                    vec.push_back(make_pair(i, j));
                }
            }
        }
        for (int i=0; i< vec.size(); i++){
            auto colAndRow= vec[i];
            int row=colAndRow.first;
            int col= colAndRow.second;
            int k=0;
            //for row
            while(k<mat[row].size()){
                mat[row][k]=0;
                k++;
                
            }
           //for column
           int j=0;
           while(j< mat.size()){
               mat[j][col]=0;
               j++;
           }
            
        }
        
        
    }
};