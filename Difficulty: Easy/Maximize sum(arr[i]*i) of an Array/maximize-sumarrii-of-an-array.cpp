//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        // Convert the array to a vector for easier manipulation
        vector<int> arr(a, a + n);
    
        // Sort the array
        sort(arr.begin(), arr.end());
    
        long long result = 0;
        const int MOD = 1e9 + 7;
    
        // Calculate the sum of (i * arr[i]) % MOD
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)i * arr[i]) % MOD;
        }
    
        return result;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends