//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
	int count(int arr[], int n, int x) {
	    int first = -1, last = -1, l = 0, r = n - 1;
	    while(l <= r) {
	        int mid = l + (r - l) / 2;
	        if(arr[mid] == x) {
	            first = mid;
	            r = mid - 1;
	        }
	        else if(arr[mid] < x)
	            l = mid + 1;
	        else
	            r = mid - 1;
	    }
	    l = 0;
	    r = n - 1;
	    while(l <= r) {
	        int mid = l + (r - l) / 2;
	        if(arr[mid] == x) {
	            last = mid;
	            l = mid + 1;
	        }
	        else if(arr[mid] < x)
	            l = mid + 1;
	        else
	            r = mid - 1;
	    }
	    return (first == -1 && last == -1) ? 0 : (last - first + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends