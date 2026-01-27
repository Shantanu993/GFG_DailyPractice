class Solution {
  public:
    int n;
    int m;
    
    int row[4] = {-1,+1,0,0};
    int col[4] = {0,0,-1,+1};
    
    bool check(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    bool find(vector<vector<char>> &mat,vector<vector<bool>> &visited, string &word,int index,int i,int j){
        
        if(index==word.size())return 1;
        
        for(int k=0;k<4;k++){
            
            if(check(i+row[k],j+col[k]) && visited[i+row[k]][j+col[k]]==0 && mat[i+row[k]][j+col[k]]==word[index]){
                visited[i+row[k]][j+col[k]]=1;
                if(find(mat,visited,word,index+1,i+row[k],j+col[k]))return 1;
                visited[i+row[k]][j+col[k]]=0;
                
            }
        }
        
        return 0;
        
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        vector<vector<bool>>visited(mat.size(),vector<bool>(mat[0].size(),0));
        
        n = mat.size();
        m = mat[0].size();
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                 
                if(word[0]==mat[i][j]){
                    visited[i][j] = 1;
                    if(find(mat,visited,word,1,i,j))return true;
                    visited[i][j] = 0;
                }
                
            }
        }
        
        return false;
    }
};