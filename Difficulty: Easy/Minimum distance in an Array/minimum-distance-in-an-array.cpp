//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        // code here
         int ans=INT_MAX;
    int in1=-1,in2=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
           in1=i;
        }
        if(arr[i]==y){
            in2=i;
        }
      if(in1!=-1 && in2!=-1){
        int diff=abs(in1-in2);
        ans=min(diff,ans);
      }

    }
    if(ans==INT_MAX){
        return -1;
    }else{
        return ans;
    }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends