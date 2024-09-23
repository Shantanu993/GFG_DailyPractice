//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long s = ((long long)n*(n+1))/2;
        long long s1 = ((long long)n*(n+1)*(2*n+1))/6;
        long sm = 0,sq=0;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            sq+=((long long)arr[i]*arr[i]);
        }
        long long xmy = s-sm;
        long long xpy = (s1-sq)/xmy;
        long long m = (xmy+xpy)/2;
        long long r = xpy-m;
        return {r,m};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends