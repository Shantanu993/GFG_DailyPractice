//{ Driver Code Starts
// Initial Template for java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            int n = Integer.parseInt(S[0]);
            int m = Integer.parseInt(S[1]);
            int k = Integer.parseInt(S[2]);
            int mat[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                String S1[] = read.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    mat[i][j] = Integer.parseInt(S1[j]);
                }
            }
            Solution ob = new Solution();
            int ans[][] = ob.rotateMatrix(k, mat);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends


// User function template for java

class Solution {
    int[][] rotateMatrix(int K, int Mat[][]) {
        int N = Mat.length;      // Number of rows
        int M = Mat[0].length;   // Number of columns
        
        K = K % M;  // Adjust K to be within the bounds of column size
        for (int i = 0; i < N; i++) {
            reverse(Mat, 0, K - 1, i);
            reverse(Mat, K, M - 1, i);
            reverse(Mat, 0, M - 1, i);
        }
        return Mat;
    }
    public static void reverse(int[][] Mat, int left, int right, int i) {
        while (left <= right) {
            int temp = Mat[i][left];
            Mat[i][left] = Mat[i][right];
            Mat[i][right] = temp;
            left++;
            right--;
        }
    }
}