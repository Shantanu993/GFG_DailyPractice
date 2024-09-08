//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int activitySelection(vector<int> start, vector<int> end, int n) {
        // Pair the start and end times
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; ++i) {
            activities.push_back({end[i], start[i]}); // Store end time first to sort by end time
        }
        
        // Sort activities by their end times
        sort(activities.begin(), activities.end());
        
        int count = 0;
        int last_end_time = INT_MIN;
        
        // Iterate through sorted activities
        for (const auto& activity : activities) {
            int current_end = activity.first;
            int current_start = activity.second;
            
            // If the current activity starts after the last selected activity ends
            if (current_start > last_end_time) {
                count++;
                last_end_time = current_end; // Update last_end_time to the end time of the current activity
            }
        }
        
        return count;
    }
};
    

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends