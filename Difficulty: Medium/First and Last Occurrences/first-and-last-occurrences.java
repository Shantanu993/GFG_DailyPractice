//{ Driver Code Starts
//Initial Template for Java



import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function Template for Java


//User function Template for Java


class GFG
{
   public int first(int arr[],int n, int x){
        int s=0;
        int e=n-1;
        int ans=-1;
        while (s<=e) {
            int m=s+(e-s)/2;
            if(arr[m]==x){
                ans=m;
                e=m-1;
            }else if(arr[m]<x){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return ans;
    }
    public int last(int arr[],int n, int x){
        int s=0;
        int e=n-1;
        int ans=-1;
        while (s<=e) {
            int m=s+(e-s)/2;
            if(arr[m]==x){
                ans=m;
                s=m+1;
            }else if(arr[m]<x){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return ans;
    }
    ArrayList<Integer> find(int arr[], int n, int x)
    {
        // code here
        int i=first(arr,n,x);
        int j=last(arr,n,x);
        ArrayList<Integer> ans=new ArrayList<>();
        ans.add(i);
        ans.add(j);
        return ans;
    }
}



//{ Driver Code Starts.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
//            int n = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] q = line.trim().split("\\s+");
            int n =Integer.parseInt(q[0]);
            int x =Integer.parseInt(q[1]);
//            //int y =Integer.parseInt(q[2]);
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(a1[i]);
            }
            GFG ob = new GFG();
            ArrayList<Integer> ans=ob.find(arr,n,x);
            System.out.println(ans.get(0)+" "+ans.get(1));
        }
    }
}

// } Driver Code Ends