//{ Driver Code Starts
//Initial Template for Java
import java.util.stream.Collectors; 
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().print2largest(arr, n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
     int print2largest(int arr[], int n) {
        int max= Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;
        for(int a =0 ;a<n ;a++){
            max = Math.max(max,arr[a]);
        }
        for(int a =0; a<n ;a++){
            if(second<arr[a] && arr[a]!=max){
                second = arr[a];
            }
        }
        if(second==Integer.MIN_VALUE) return -1;
        return second;
    }
}