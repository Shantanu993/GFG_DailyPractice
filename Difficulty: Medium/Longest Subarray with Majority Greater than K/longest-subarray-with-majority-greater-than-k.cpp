//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
          int sum=0;
        
        int maxi=0;
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
              
              if (arr[i]>k) sum+=1; 
              else  sum-=1;
              
              if (sum>0  )  maxi=max(maxi,i+1);
               
              if (mp.find(sum-1)!=mp.end() ){
                     maxi=max(maxi,i-mp[sum-1]);
              }
              if (mp.find(sum)==mp.end() ){
                     mp[sum]=i;
              }
              
              
        }
        
        return maxi;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends