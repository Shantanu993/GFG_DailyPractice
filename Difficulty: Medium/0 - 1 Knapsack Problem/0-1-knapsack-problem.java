//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class gfg
{
    public static void main(String args[])throws IOException
    {
        //reading input using BufferedReader class
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        
        //reading total testcases
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            //reading number of elements and weight
            int n = Integer.parseInt(read.readLine());
            int w = Integer.parseInt(read.readLine());
            
            int val[] = new int[n];
            int wt[] = new int[n];
            
            String st[] = read.readLine().trim().split("\\s+");
            
            //inserting the values
            for(int i = 0; i < n; i++)
              val[i] = Integer.parseInt(st[i]);
             
            String s[] = read.readLine().trim().split("\\s+"); 
            
            //inserting the weigths
            for(int i = 0; i < n; i++)
              wt[i] = Integer.parseInt(s[i]);
              
            //calling method knapSack() of class Knapsack
            System.out.println(new Solution().knapSack(w, wt, val, n));
        }
    }
}




// } Driver Code Ends


class Solution 
{ 
    //Function to return max value that can be put in knapsack of capacity W.
    static int knapSack(int W, int wt[], int val[], int n) 
    { 
         // your code here 
         
        int[][] dp = new int[n + 1][W+ 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return fun(W, wt, val, n, dp);
    }
    
    
     private static int fun(int w, int[] wt, int[] val, int n, int[][] t) {
        // Base Case
        if (n <= 0 || w <= 0)
            return 0;

        // Check if result exists already
        if (t[n][w] != -1)
            return t[n][w];

        // If result doesn't exist
        // Choice Diagram Code
        // 1. Choice to include item or not
        if (wt[n - 1] <= w) {
            t[n][w] = Math.max(val[n - 1] + fun(w - wt[n - 1], wt, val, n - 1, t), fun(w, wt, val, n - 1, t));
            return t[n][w];
        }
        // 2. No choice
        else if (wt[n - 1] > w) {
            t[n][w] = fun(w, wt, val, n - 1, t);
            return t[n][w];
        }
        return 0; // Return 0 for non-reachable code (to satisfy Java compiler)
    }

         
         
    
}


