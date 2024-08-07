//{ Driver Code Starts
// Initial Template for Java

import java.util.*;

class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

// } Driver Code Ends


// User function Template for Java

// m is the given matrix and n is the order of matrix
class Solution {
private void solve(int i, int j, int a[][], int n, ArrayList < String > ans, String move,
    int vis[][]) {
    if (i == n - 1 && j == n - 1) {
      ans.add(move);
      return;
    }

    // downward
    if (i + 1 < n && vis[i + 1][j] == 0 && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      solve(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && vis[i][j - 1] == 0 && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      solve(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && vis[i][j + 1] == 0 && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      solve(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && vis[i - 1][j] == 0 && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      solve(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }
  }
    
    public ArrayList<String> findPath(int[][] mat) {
        int n=mat.length;
         

        ArrayList<String> ans=new ArrayList<>();
        
        int[][] vis=new int[n][n];
        for(int i=0;i<vis.length;i++){
            for(int j=0;j<vis[0].length;j++){
                vis[i][j]=0;
            }
        }
        
        
        if(mat[0][0]==1) solve(0,0,mat,n,ans,"",vis);
        
        return ans;
    }
}