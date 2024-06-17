//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int[] nums = new int[n];
            String[] S = br.readLine().trim().split(" ");
            for(int i = 0; i < n; i++)
                nums[i]  =Integer.parseInt(S[i]);
            int k = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            System.out.println(obj.solveWordWrap(nums, k));
        }
    }
}

// } Driver Code Ends


class Solution
{
    public int solveWordWrap (int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE); 
        dp[n] = 0;
        for(int i=n-1; i>=0; i--) {
            int sum = 0;
            for(int j=i; j<n && sum + nums[j]<=k; j++) {
                sum += nums[j];
                int spaces = (j != n-1) ? k-sum : 0;
                dp[i] = Math.min(dp[i], spaces*spaces+dp[j+1]);
                sum++;
            }
        } 
        return dp[0];
    }
}