//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int arr[]= new int[N];
            for(int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            int sum = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            if(ob.isSubsetSum(N, arr, sum))
            System.out.println(1);
            else
            System.out.println(0);

            
        }
    }
}

// } Driver Code Ends



class Solution{
    
    static Boolean isSubsetSum(int N, int arr[], int sum){
        int totalSum = 0;
        for(int i=0;i<N;i++){
            totalSum += arr[i];
        }
        boolean [][] dp = new boolean[N][totalSum+1];
        for(int i=0;i<N;i++){
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        if(sum>totalSum){
            return false;
        }
        
        for(int ind=1;ind<N;ind++){
            for(int target=1;target<=sum;target++){
                boolean notTaken = dp[ind-1][target];
                boolean taken = false;
                if(arr[ind]<=target){
                    taken = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = taken || notTaken;
            }
        }
        return dp[N-1][sum];
    }
}