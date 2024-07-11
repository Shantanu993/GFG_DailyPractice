//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String line = in.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int key = Integer.parseInt(in.readLine().trim());

            out.println(new Solution().search(arr, key));
        }
        out.close();
    }
}
// } Driver Code Ends



class Solution {
    int search(int[] arr, int key) {
        int lo = 0;
        int hi = arr.length - 1;
        
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] == key)   return mid;
            if(arr[lo] <= arr[mid]){
                if(arr[lo] <= key && arr[mid] > key)    hi = mid - 1;
                else    lo = mid + 1;
            }
            else{
                if(arr[hi] >= key && arr[mid] < key)    lo = mid + 1;
                else    hi = mid - 1;
            }
        }
        return -1;
    }
}