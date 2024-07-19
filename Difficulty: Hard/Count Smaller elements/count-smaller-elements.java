//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int arr[] = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }

            int[] ans = new Solution().constructLowerArray(arr);
            for (int i = 0; i < arr.length; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends




// User function Template for Java
class Solution {

    private static int merge(int[] arr, int[] indices, int low, int mid, int high, int[] count) {
        ArrayList<Integer> temp = new ArrayList<>(); // temporary array to store sorted indices
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        int cnt = 0;

        // Storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[indices[left]] <= arr[indices[right]]) {
                temp.add(indices[left]);
                count[indices[left]] += cnt; // Add the count of smaller elements on the right
                left++;
            } else {
                temp.add(indices[right]);
                cnt++;
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.add(indices[left]);
            count[indices[left]] += cnt; // Add the count of smaller elements on the right
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.add(indices[right]);
            right++;
        }

        // Transfer all elements from temporary to indices
        for (int i = low; i <= high; i++) {
            indices[i] = temp.get(i - low);
        }
        return cnt;
    }

    public static void mergeSort(int[] arr, int[] indices, int low, int high, int[] count) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, indices, low, mid, count);  // Left half
        mergeSort(arr, indices, mid + 1, high, count); // Right half
        merge(arr, indices, low, mid, high, count);  // Merging sorted halves
    }

    public static int[] countSmallerElements(int[] arr) {
        int n = arr.length;
        int[] indices = new int[n];
        int[] count = new int[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        mergeSort(arr, indices, 0, n - 1, count);
        return count;
    }

    // Wrapper method to match the name used in the main method
    public int[] constructLowerArray(int[] arr) {
        return countSmallerElements(arr);
    }
}