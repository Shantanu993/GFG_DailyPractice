//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        map<int,int> mpp;
        
        int count  =0;
        int sum = 0;
        mpp[0] = 1;
        
        for(int i =0;i<n;i++){
            
            sum+=arr[i];
            mpp[sum]++;
            int dum = sum - k;
            
            auto it = mpp.find(dum);
            if(it != mpp.end()){
                count+=mpp[dum];
            }
        }
        return count;
        
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
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends