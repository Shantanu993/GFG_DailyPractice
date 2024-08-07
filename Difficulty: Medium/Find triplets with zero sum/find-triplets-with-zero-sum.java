//{ Driver Code Starts
import java.util.*;
class Triplets{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			int n=sc.nextInt();
			int[] a=new int[n];
			for(int i=0;i<n;i++){
				a[i]=sc.nextInt();
			}
			Solution g=new Solution();
			if(g.findTriplets(a,n))
				System.out.println("1");
			else
				System.out.println("0");
			
		}
	}
}
// } Driver Code Ends


/*Complete the function below*/



class Solution
{
    // arr[]: input array
    // n: size of the array
    //Function to find triplets with zero sum.
	public boolean findTriplets(int arr[] , int n)
    {
        //add code here.
        for(int i=0;i<n-2;i++)
        {
            HashSet<Integer> set = new HashSet<>();
            int currsum = 0-arr[i];
            for(int j=i+1;j<n;j++)
            {
                int req = currsum-arr[j];
                if(set.contains(req))
                {
                    return true;
                }
                else
                {
                    set.add(arr[j]);
                }
            }
        }
        return false;
    }
}