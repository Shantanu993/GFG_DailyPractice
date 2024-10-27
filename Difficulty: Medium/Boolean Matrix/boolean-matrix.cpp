//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends




class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
      int row=matrix.size();
      int col=matrix[0].size();
      
       vector<vector<int>> temp(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
              
                 temp[i][j]=matrix[i][j];
             }
          }
      
      
      
       
      
      for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
              if(temp[i][j]==1)
             { for(int k=0;k<col;k++){
                 matrix[i][k]=1;
                  
              }
              
              break;
                 
             }
          }
      }
        
      for(int i=0;i<col;i++){
          
          for(int j=0;j<row;j++){
              if(temp[j][i]==1){
                  
                  for(int k=0;k<row;k++){
                      matrix[k][i]=1;
                  }
                  
                break;  
              }
          }
      }  
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends