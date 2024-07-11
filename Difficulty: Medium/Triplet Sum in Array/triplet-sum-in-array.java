//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int X = Integer.parseInt(inputLine[1]);
            int A[] = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                A[i] = Integer.parseInt(inputLine[i]);
            }
            Solution ob = new Solution();
            boolean ans = ob.find3Numbers(A, n, X);
            System.out.println(ans ? 1 : 0);
        }
    }
}
// } Driver Code Ends






// User function Template for Java

class Solution {
        /**
     * only applicable for sorted arrays
     * @param arr
     * @param sum
     * @param startIndex
     * @return
     */
    public static boolean isPair(int[] arr, int sum, int startIndex) {
        int endIndex = arr.length - 1;

        while (startIndex < endIndex) {
            int currentSum = arr[startIndex] + arr[endIndex];
            if (currentSum == sum) {
                return true;
            } else if (currentSum < sum) {
                startIndex++;
            } else {
                endIndex--;
            }
        }

        return false;
    }
    public static boolean find3Numbers(int arr[], int n, int sum) {
        // Your code Here
        Arrays.sort(arr);
        for (int i = 0; i < arr.length - 2; i++) {
            if (isPair(arr, sum - arr[i], i + 1)) {
                return true;
            }
        }

        return false;
    }
}