//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {

        // taking input using Scanner class
        Scanner sc = new Scanner(System.in);

        // taking total testcases
        int t = sc.nextInt();
        while (t > 0) {

            // taking size of array
            int n = sc.nextInt();
            int array[] = new int[n];

            // inserting elements in the array
            for (int i = 0; i < n; ++i) {
                array[i] = sc.nextInt();
            }

            // creating an object of class Solution
            Solution ob = new Solution();

            // calling longestSubsequence() method of class
            // Solution
            System.out.println(ob.longestSubsequence(n, array));
            t--;
        }
    }
}
// } Driver Code Ends





class Solution 
{
    //Function to find length of longest increasing subsequence.
    //following code is alternative
  /*  public static int lcs(int a[], int a2[]){
        int n =a.length;
        int m =a2.length;
        int dp[][]= new int[n+1][m+1];
        for(int i =1;i<n+1;i++){
            for(int j =1;j<m+1;j++){
                if(a[i-1]==a2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    
                }else{
                    int ans1=dp[i-1][j];
                    int ans2=dp[i][j-1];
                    dp[i][j]=Math.max(ans1,ans2);
                }
            }
        }
        return dp[n][m];
    }
    static int longestSubsequence(int size, int a[])
    {
        // code here
        HashSet<Integer> set=new HashSet<>();
        for(int i =0;i<size;i++){
            set.add(a[i]);
        }
        int a2[]= new int[set.size()];
        int i =0;
        for(int num : set){
            a2[i]=num;
            i++;
        }
        Arrays.sort(a2);
        return lcs(a,a2);
    }*/
     static int longestSubsequence(int size, int a[])
    {
    ArrayList<Integer> list =new ArrayList<>();
        list.add(a[0]);
        for(int i=1; i<size; i++){
            if(a[i] > list.get(list.size()-1)) {
                list.add(a[i]);
            }else{
                int pos = lowerBound(list, a[i]);
                list.set(pos, a[i]);
            }
        }
        return list.size();
     }
     public static int lowerBound(ArrayList<Integer> list, int elem){
        int low=0, high=list.size()-1, mid=0;
        while(low<=high){
            mid = (low+high)/2;
            if(list.get(mid) >= elem){
                high = mid-1;
            }else low = mid+1;
        }
        return low;
    }
} 