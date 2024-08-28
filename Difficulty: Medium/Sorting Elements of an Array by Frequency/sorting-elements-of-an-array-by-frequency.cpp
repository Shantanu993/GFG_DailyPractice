//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int,int> m;
        for(auto it:arr){
            m[it]++;
        }
        
        multimap<int,int,greater<int>> mm;
        
        for(auto it:m){
            mm.insert({it.second,it.first});
        }
        vector<int> ans;
        
        for(auto it:mm){
            for (int j = 0; j < it.first; j++) {
            ans.push_back(it.second);
        }

        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends