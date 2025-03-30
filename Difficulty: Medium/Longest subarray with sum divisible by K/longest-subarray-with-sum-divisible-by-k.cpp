//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        unordered_map<int,int> mapp;
        int  n = arr.size();
        int sum = 0, ans =0;
        for(int i = 0 ; i < n ; i++)
        {
            sum = ((sum+arr[i])%k+k)%k;
            
            if(sum == 0)
            {
                ans = i+1;
            }
            
            else if(mapp.find(sum)!= mapp.end())
            {
                ans = max(ans,i - mapp[sum]);
            }
            else
            {
                mapp[sum] = i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.longestSubarrayDivK(arr, d);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends