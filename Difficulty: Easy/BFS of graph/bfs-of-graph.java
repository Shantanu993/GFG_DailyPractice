//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                // adj.get(v).add(u);
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.bfsOfGraph(V, adj);
            for (int i = 0; i < ans.size(); i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends



class Solution {
  public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> ans = new ArrayList<Integer>();
        HashSet<Integer> visited = new HashSet<Integer>();
        Queue<ArrayList<Integer>> que = new LinkedList<ArrayList<Integer>>();
        que.add(adj.get(0));
        visited.add(0);
        ans.add(0);
        while(!que.isEmpty()){
            ArrayList<Integer> temp = que.poll();
            for(int i=0;i<temp.size();i++){
                if(!visited.contains(temp.get(i))){
                    que.add(adj.get(temp.get(i)));
                    visited.add(temp.get(i));
                    ans.add(temp.get(i));
                }
            }
        }
        return ans;
    }
}