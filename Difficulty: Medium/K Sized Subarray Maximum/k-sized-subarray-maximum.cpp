//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n=arr.size();
        vector<int> ans;
        // int maxi=arr[0];
        // int prev2=arr[1];
        // int prev1=arr[2];
        
        // maxi=max(maxi,max(prev1,prev2));
        
        // ans[0]=maxi;
    
        // int j=1;
        
        // for(int i=0;i<n;i++){
        //     maxi=max(arr[i],max(prev1,prev2));
        //         ans[j]=maxi;
        //         j++;
        //         prev1=arr[i];
        //         prev2=arr[i-1];
            
        // }
        deque<int>dq;
        for(int i=0;i<n;i++){
            
            //remove elements from front of deque
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends