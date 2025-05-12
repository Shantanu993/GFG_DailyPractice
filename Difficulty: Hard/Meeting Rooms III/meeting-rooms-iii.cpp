//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        vector<int> cnt(n, 0); // Count of meetings per room
        // Min-heap for occupied rooms: (end time, room number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            occ;
        // Min-heap for available rooms: room numbers
        priority_queue<int, vector<int>, greater<int>> avail;

        // Initialize all rooms as available
        for (int i = 0; i < n; ++i)
            avail.push(i);

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        for (auto &m : meetings) {
            int s = m[0], e = m[1];

            // Release rooms that have become available by time s
            while (!occ.empty() && occ.top().first <= s) {
                avail.push(occ.top().second);
                occ.pop();
            }

            if (!avail.empty()) {
                // Assign to the smallest available room
                int r = avail.top();
                avail.pop();
                occ.push({e, r});
                cnt[r]++;
            } else {
                // All rooms are occupied; assign to the room that becomes free earliest
                int t = occ.top().first;
                int r = occ.top().second;
                occ.pop();
                occ.push({t + (e - s), r});
                cnt[r]++;
            }
        }

        // Find the room with the maximum number of meetings
        int maxCnt = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > maxCnt) {
                maxCnt = cnt[i];
                res = i;
            }
        }

        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends