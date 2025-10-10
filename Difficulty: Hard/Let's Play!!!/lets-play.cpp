// User function Template for C++

class Solution {
  public:
    int isSuperSimilar(int n, int m, vector<vector<int>>& mat, int x)
    {
        // code here
        x=x%m;
        for (int i=0;i<n;i++) { 
            for (int j=0;j<m;j++) { 
                if (i%2==0) { 
                    if (mat[i][j]!=mat[i][((m-x)+j)%m]) return 0;
                }
                else { 
                    if (mat[i][j]!=mat[i][(x+j)%m]) return 0;
                }
            }
        }
        return 1;
    }
};