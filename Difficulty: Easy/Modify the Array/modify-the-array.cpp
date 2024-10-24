//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &a) {
        deque<int>dq;
        int n=a.size();
        if(n==1) return a;
        dq.push_back(a[0]);
        for(int i=1;i<n;i++){
            int curr=a[i];
            while(!dq.empty() && dq.back()==curr){
                dq.pop_back();
                curr+=curr;
            }
            dq.push_back(curr);
        }
        vector<int>ans;
        int rem=n;
        while(!dq.empty()){
            int ele=dq.front();
            dq.pop_front();
            if(!ele) continue; // for inserting only non zero elements
            ans.push_back(ele);
            rem--;
        }
        while(rem--){
            ans.push_back(0);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends