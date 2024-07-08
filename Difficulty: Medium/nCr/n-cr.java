//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String read[] = in.readLine().trim().split("\\s+");
            int n = Integer.parseInt(read[0]);
            int r = Integer.parseInt(read[1]);
            
            Solution ob = new Solution();
            System.out.println(ob.nCr(n, r));
        }
    }
}
// } Driver Code Ends




// User function Template for Java

class Solution{
    static int mod = 1000000007;
    static int nCr(int n, int r)
    {
        if(r>n){
            return 0;
        }
        if(r==n){
            return 1;
        }
        if(n-1==r){
            return n;
        }
        int [][]tp = new int[n+1][r+1];
        for(int []a : tp){
            Arrays.fill(a,-1);
        }
       return (factorial(n, r, tp)%mod);
    }
    
    static int factorial(int n, int r, int[][]tp){
        
        if(n==r||r==0){
            return 1;
        }
        if(tp[n][r]!=-1){
            return tp[n][r];
        }
        tp[n][r] = (factorial(n-1, r-1, tp)+factorial(n-1, r, tp))%mod;
        
        return tp[n][r];
        
    }
}