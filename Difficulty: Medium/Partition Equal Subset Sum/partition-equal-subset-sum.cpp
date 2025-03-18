//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    vector<vector<int>>dp;
    bool solve(int idx, int tgt, vector<int>& arr){
        if(tgt==0) return true;
        if(idx<0 || tgt<0) return false;
        if(dp[idx][tgt]!=-1) return dp[idx][tgt];
        bool pick = solve(idx-1,tgt-arr[idx],arr);
        bool notPick = solve(idx-1,tgt,arr);
        return dp[idx][tgt] = (pick || notPick);
    }
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int target =  accumulate (arr.begin(),arr.end(),0);
        if (target % 2 != 0)
            return false;
        dp = vector<vector<int>>(n,vector<int>(target/2+1,-1));
        return solve(n-1, target/2, arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends