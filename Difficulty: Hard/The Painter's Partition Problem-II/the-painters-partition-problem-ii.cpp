//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        long long start = 0 , end = 0 , mid , ans ;
        for(int i=0;i<n;i++){
            if(start<arr[i]){
                start = arr[i];
            }
                end += arr[i];
        }
            while(start<=end){
                long long count = 1 , pages = 0;
                mid = start + (end-start)/2;
                for(int i=0;i<n;i++){
                   pages += arr[i];
                   if(pages>mid)
                   {
                       count++;
                       pages = arr[i];
                   }
                }
                if(count<=k){
                    ans = mid ;
                    end = mid -1;
                }
                else{
                    start = mid+1;
                }
            }
            return ans ;
        
        // return minimum time
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends