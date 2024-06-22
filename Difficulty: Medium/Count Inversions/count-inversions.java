//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();

        while (t-- > 0) {
            long n = sc.nextLong();
            long arr[] = new long[(int)n];

            for (long i = 0; i < n; i++) arr[(int)i] = sc.nextLong();

            System.out.println(new Solution().inversionCount(arr, (int)n));
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    static long inversionCount(long arr[], int n) {
        // Your Code Here
        return mrgSrt(arr, 0, n - 1);
    }
    public static long mrgSrt(long arr[],int l,int h){
        long cnt=0;
        if(l>=h) return cnt=0;
        int m=(l+h)/2;
        cnt+=mrgSrt(arr,l,m);
        cnt+=mrgSrt(arr,m+1,h);
        cnt+=mrg(arr,l,m,h);
        return cnt;
    }
    public static long mrg(long arr[],int l,int m,int h){
        ArrayList<Long> temp = new ArrayList<>();
        long cnt=0;
        int lft=l;
        int rig=m+1;
        while(lft<=m && rig<=h){
            if(arr[lft]<=arr[rig]){
                temp.add(arr[lft]);
                lft++;
            }
            else{
                temp.add(arr[rig]);
                cnt+=(m-lft)+1;
                rig++;
            }
        }
        while(lft<=m){
            temp.add(arr[lft]);
            lft++;
        }
        while(rig<=h){
            temp.add(arr[rig]);
            rig++;
        }
        for(int i=l;i<=h;i++){
            arr[i]=temp.get(i-l);
        }
        return cnt;
    }
}