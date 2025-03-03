//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size() , s = -1, e = -1, mx = 0;
        multiset<int>st;
        for(int i=0,j=0;i<n;i++){
            st.insert(arr[i]);
            while(st.size()>1 && (*st.rbegin() - *st.begin()) > x)st.erase(st.find(arr[j++]));
            int l = i - j + 1;
            if(l > mx) mx = l, s = j, e = i+1;
        }
        return  vector<int>(arr.begin()+s,arr.begin()+e);
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends