//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        // need to sort on end[] basis 
        // hence, will sort using .second for ascending sort. 
        return a.second < b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Approach :-------- Greedy Approach 
        
        // Step 1 : Create a vector to store (start,end) in a sorted order of the end array
        vector<pair<int, int>> v;
        
        // Step 2 : Populate the vector 
        for(int i = 0; i < n; i++){
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        
        // Step 3 : Sort the vector using custom comparator
        sort(v.begin(), v.end(), cmp);
        
        // Step 4 : Initialize a counter to count meetings done
        // and currMeetingEnd indicating the end time of the current meeting
        int count = 1;
        int currMeetingEnd = v[0].second;
        
        // Step 5 : Iterate through the vector to check if we can start next meeting
        for(int i = 1; i < n; i++){
            // check if next meeting's start time is greater than currMeetingEnd
            if(v[i].first > currMeetingEnd){
                count++;
                currMeetingEnd = v[i].second;
            }
        }
        
        return count;
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
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends