//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool solveCanReach(vector<int> &arr, int index){
        
        if(index >= arr.size()-1){
            return true;
        }
        
        if(arr[index]==0){
            return false;
        }
        
        int possibleJumps = arr[index];
        for(int i = 1 ;i<=possibleJumps;i++){
            int nextJump = i+ index;
            if(solveCanReach(arr,nextJump)){
                return true;
            }
        }
        
        return false;
    }
    bool canReach(vector<int> &arr) {
        int n = arr.size();
        vector<bool>dp(n,false);
        return solveCanReach(arr,0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        int ans = ob.canReach(a);

        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends