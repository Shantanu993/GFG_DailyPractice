//{ Driver Code Starts
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
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, adj);
            if (ans)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


class Solution {
    static boolean find(int par, int i,ArrayList<ArrayList<Integer>> adj,int visited[],HashSet<Integer> hs){
        if(visited[i]==1 ) return true;
        visited[i]=1; 
        for(int val : adj.get(i)){
            if(val==par) continue;
            if(find(i,val,adj,visited,hs)) return true;
        }
        return false;
    }
    public boolean isCycle(int v, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        int visited[] = new int[v];
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                HashSet<Integer> hs = new HashSet();
                if(find(-1,i,adj,visited,hs)){ 
                    return true;
                } 
            }
        }
        return false;
    }
}
