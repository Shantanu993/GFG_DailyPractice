//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        vector<int> a(arr.size(),arr.size());
        
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                a[arr[i]] = arr[i];
            }
            else if(a[i] == arr.size()){
                a[i]=-1;
            }
        }
        for(int i=0;i<arr.size();i++){
            if(a[i]==arr.size()){
                a[i] = -1;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends