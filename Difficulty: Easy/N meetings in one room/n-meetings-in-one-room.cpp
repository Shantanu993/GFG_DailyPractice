//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxMeetings(int n, int s[], int e[]) {

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({e[i],s[i]});
        }
        sort(v.begin(),v.end());
        int ans=1,last=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>last){
                ans++;
                last=v[i].first;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends