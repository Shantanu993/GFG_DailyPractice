//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>result;
        int s1=arr[0][0],e1=arr[0][1];
        for(int i=1;i<arr.size();i++)
        {
            if(e1>=arr[i][0])
            {
                e1=max(e1,arr[i][1]);
            }
            else
            {
                result.push_back({s1,e1});
                s1=arr[i][0];
                e1=arr[i][1];
            }
        }
        result.push_back({s1,e1});
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends