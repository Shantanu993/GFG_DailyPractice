//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
          int n = arr.size(), st = 0, en = n - 1;
        
        while (st < en) {
            if (arr[st] < arr[en])        
                return arr[st];
               
            int mid = st + (en - st) / 2;
            
            if (arr[en] < arr[mid]) {
                st = mid + 1;
            } else {
                en = mid;
            }
        }
        
        return arr[st];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends