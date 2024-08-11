//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends


class Solution 
{
public:
    static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }
    
    // Function to find the maximum profit and the number of jobs done.
    std::vector<int> JobScheduling(Job arr[], int n) { 
        // Sort jobs according to their profit in descending order.
        std::sort(arr, arr + n, comp);
        
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].dead > maxDeadline) {
                maxDeadline = arr[i].dead;
            }
        }
        
        // Array to keep track of which slots are free.
        std::vector<int> slots(maxDeadline + 1, -1);
        
        int jobCount = 0;
        int totalProfit = 0;
        
        // Iterate over all jobs
        for (int i = 0; i < n; i++) {
            // Find a slot for this job, starting from its deadline
            for (int j = arr[i].dead; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = arr[i].id;
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {jobCount, totalProfit};
    } 

};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends