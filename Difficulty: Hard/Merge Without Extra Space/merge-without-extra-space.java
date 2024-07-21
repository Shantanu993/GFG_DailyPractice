//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.io.*;

public class Main
{
    public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    String inputLine[] = br.readLine().trim().split(" ");
		    int n = Integer.parseInt(inputLine[0]);
		    int m = Integer.parseInt(inputLine[1]);
		    long arr1[] = new long[n];
		    long arr2[] = new long[m];
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<n; i++){
		        arr1[i] = Long.parseLong(inputLine[i]);
		    }
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<m; i++){
		        arr2[i] = Long.parseLong(inputLine[i]);
		    }
		    Solution ob = new Solution();
		    ob.merge(arr1, arr2, n, m);
		    
		    StringBuffer str = new StringBuffer();
		    for(int i=0; i<n; i++){
		        str.append(arr1[i]+" ");
		    }
		    for(int i=0; i<m; i++){
		        str.append(arr2[i]+" ");
		    }
		    System.out.println(str);
		}
	}
}

// } Driver Code Ends




//User function Template for Java
class Solution{   // tc   and sc is as given in the question
    
    static void swapIfGreater(long arr1[], long arr2[], int ind1, int ind2){
        if(arr1[ind1] > arr2[ind2]){
            //swap
            long temp = arr1[ind1];
            arr1[ind1] = arr2[ind2];
            arr2[ind2] = temp;
        }
    }
    
    public static void merge(long arr1[], long arr2[], int n, int m) 
        
    {
            int len = n + m;
            int gap = (len/2) + (len%2);
            
            while(gap > 0){
                int left = 0;
                int right = left + gap;
                
                while(right < len){
                    if(left < n && right >=n) //arr1 and arr2
                    {
                        swapIfGreater(arr1,arr2,left, right-n);
                    }
                    else if(left >=n){  // arr2 and arr2
                        swapIfGreater(arr2,arr2,left-n,right-n);
                    }
                    else{    //arr1 and arr1
                        swapIfGreater(arr1,arr1,left,right);
                    }
                    
                    left++;
                    right++;
                }
                
                if(gap == 1) break;
                gap = (gap/2) + (gap % 2);
            }
        }
        
}
