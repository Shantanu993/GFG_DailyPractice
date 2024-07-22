//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            int N = sc.nextInt();
            int M[][] = new int[N][N];
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    M[i][j] = sc.nextInt();
                }
            }
            System.out.println(new Solution().celebrity(M,N));
            t--;
        }
    } 
} 
// } Driver Code Ends


class Solution
{ 
    //Function to find if there is a celebrity in the party or not.
    int celebrity(int M[][], int n)
    {
    	int start = 0;
    	int end = n-1;
    	while(start<end){
    	    if(M[start][end]==1) start++;
    	    else if(M[end][start]==1) end--;
    	    else{
    	        start++;
    	        end--;
    	    }
    	}
    	if(start==end){
    	    for(int i=0;i<n;i++){
    	        if(i!=start && (M[i][start]!=1 || M[start][i]!=0))
    	            return -1;
    	    }
    	}
    	return start;
    	
    }
}