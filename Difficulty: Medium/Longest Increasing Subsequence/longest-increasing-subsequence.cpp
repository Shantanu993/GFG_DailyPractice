//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
          int n=arr.size();
        vector<int>tmp;
        for(int i=0; i<n; i++){
            auto ind=lower_bound(tmp.begin(), tmp.end(), arr[i]);
            if(ind==tmp.end()) tmp.push_back(arr[i]);
            else *ind=arr[i];
        }
        return tmp.size();
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends