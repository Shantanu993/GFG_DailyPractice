//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int rowWithMax1s(vector<vector<int> > &arr) {
       
       int count = 0;
       int ans = -1;
       int n = arr.size();
       int m = arr[0].size();
       for(int  i = 0; i < n; i++)
       {
          int  cnt = 0;
           for(int j  = 0; j < m; j++)
           {
               if(arr[i][j] == 1)
               {
                   cnt++;
               }
               
           }
           if(count < cnt)
               {
                   count = cnt;
                   ans = i;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends