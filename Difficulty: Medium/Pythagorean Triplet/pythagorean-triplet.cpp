//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    int max_ele=arr[0];
	    for(int i=1;i<n;i++){
             max_ele=max(max_ele,arr[i]);	        
	    }
	  vector<int>count(max_ele+1,0);   // through count we can check a element is present or not
	   // in the array bs condition is that count array should be the fixed of size 
	  for(int i=0;i<n;i++){
	      count[arr[i]]++;
	  }
	  for(int i=1;i<=max_ele;i++){
	      for(int j=i+1;j<=max_ele;j++){
	          if(count[i]>0 && count[j]>0){
	                int a=i*i;
	                int b=j*j;
	                int c=a+b;
	                int d=sqrt(c);
	                if(d*d==c && d<=max_ele && count[d]>0) return true;
	          }
	      }
	  }
	  return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends