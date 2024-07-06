//{ Driver Code Starts
//Initial template for JAVA

import java.util.*;
import java.io.*;
import java.lang.*;

class Main
{
    public static void main(String args[])
    {
        //taking input using class Scanner
        Scanner sc = new Scanner(System.in);
        
        //taking total count of testcases
        int t = sc.nextInt();
        
        
        
        while(t-- > 0)
        {
            //taking total number of elements
            int n = sc.nextInt();
            
            //taking size of subArrays 
            int k = sc.nextInt();
            
            //Declaring and Intializing an array of size n
            int arr[] = new int[n];
            
            //adding all the elements to the array 
            for(int i = 0; i <n; i++)
            {
                arr[i] =sc.nextInt();
            }
            
            //Calling the method max_of_subarrays of class solve
            //and storing the result in an ArrayList
            ArrayList <Integer> res = new Solution().max_of_subarrays(arr, n, k);
            
            //printing the elements of the ArrayList
            for (int i = 0; i < res.size(); i++)
                System.out.print (res.get (i) + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


//User function template for JAVA
class Solution
{
    //Function to find maximum of each subarray of size k.
    static ArrayList <Integer> max_of_subarrays(int arr[], int n, int k)
    {
        ArrayList <Integer> list= new ArrayList<>(); 
        
        // for(int i=0; i<=n-k; i++){
        //     int max= arr[i]; 
        //     for(int j=i; j<k+i; j++){
        //         if(arr[j]> max){
        //             max=arr[j]; 
        //         }
        //     }
        //     list.add(max); 
        // }
        
        // return list;
        
        
        int i=0; // startign idx of window
        int j=k-1; //  ending index of window
        int prevMaxIdx=-1; // index of Previous max elem
        int max= Integer.MIN_VALUE; 
        
        for(int idx=i; idx<=j; idx++){
            if(arr[idx]>max){
                max=arr[idx]; 
                prevMaxIdx= idx; 
            }
        }
        
        list.add(max); 
        
        while(j<n-1){
            
            // sliding the window
            i++; 
            j++; 
            
            // now checking previous maximum is still in this window or not
            if(prevMaxIdx>=i){
                if(arr[j]<max){
                    list.add(max); 
                    continue; 
                }
                
                // now again finding the max elem in the current window
                else{
                    max=Integer.MIN_VALUE; 
                    for(int idx=i; idx<=j; idx++){
                        if(arr[idx]>max){
                            max=arr[idx];
                            prevMaxIdx = idx; 
                        }
                    }
                    list.add(max); 
                }
            }else{
                max= Integer.MIN_VALUE; 
                for(int idx= i; idx<=j; idx++){
                    if(arr[idx]>max){
                        max=arr[idx]; 
                        prevMaxIdx= idx; 
                    }
                }
                list.add(max); 
            }
        }
        return list;
    }
}