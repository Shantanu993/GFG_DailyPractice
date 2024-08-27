//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<bool> Awins(n+1, 0);
        if (x>y) swap(x, y);
        for(int i=0;i<min(x,n+1);i++){
            Awins[i] = i%2;
        }
        
        if (x>n) return Awins[n];
        Awins[x] = 1;
        for(int i=x + 1;i<min(n+1, y);i++){
            Awins[i] = !(Awins[i-1] && Awins[i-x]);
        }
        if (y>n+1) return Awins[n];
        Awins[y] = 1;
        for(int i=y+1;i < n+1;i++){
            Awins[i] = !(Awins[i-1] && Awins[i-x] && Awins[i-y]);
        }
        
        return Awins[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends