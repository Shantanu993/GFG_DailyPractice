//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for (int i = 0; i < V; i++)
                list.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
            }
            if (new Solution().isCyclic(V, list) == true)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/

class Solution {
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
      boolean[] vis = new boolean[V];
      boolean[] pvis = new boolean[V];
     for(int i=0;i<V;i++) {
         if(!vis[i]) {
             
             if(dfs(i, -1, adj, vis, pvis)) {
                 return true;
             }
         }
     }
      return false;
    }
    public boolean dfs(int src, int par, ArrayList<ArrayList<Integer>> adj, 
    boolean[] vis, boolean pvis[]) {
        vis[src] = true;
        pvis[src] = true;
        for(int a: adj.get(src)) {
            if(!vis[a]) {
                if(dfs(a, src, adj, vis, pvis)) return true;
            } else if(pvis[a]) {
                return true;
            }
        }
        pvis[src] = false;
        return false;
    }
}