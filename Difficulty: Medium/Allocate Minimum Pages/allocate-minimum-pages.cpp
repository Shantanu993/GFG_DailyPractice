//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
  
    bool possiblesol(int arr[], int n ,int m ,int mid)
    {
        int pagesum=0;
        int count=1;
        for(int i=0;i<n;i++)
        {   
            if(arr[i] >mid)
            {
                return false;
            }
            if(arr[i]+pagesum >mid)
            {
                count++;
                pagesum=arr[i];
                if(count > m)
                {
                    return false;
                }
                
            }
            else
            {
                pagesum +=arr[i];
            }
        }
        return true;
    }
    
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n)
        {
            return -1;
        }
        
        // search space
        int start=0;
        int end=accumulate(arr,arr+n,0);
        int ans=-1;
        
        while(start<=end)
        {   
            int mid=(start+end)>>1;
            if(possiblesol(arr,n,m,mid))
            {
                ans=mid;
                end=mid-1;
                
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends