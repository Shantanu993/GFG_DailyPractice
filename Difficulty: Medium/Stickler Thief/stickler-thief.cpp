//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        if (n == 2) return max(arr[0], arr[1]);
        
        int prev2 = arr[0];
        int prev1 = max(arr[0], arr[1]);
        for (int i = 2; i < n; ++i)
        {
            int curr = max(prev1, arr[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends