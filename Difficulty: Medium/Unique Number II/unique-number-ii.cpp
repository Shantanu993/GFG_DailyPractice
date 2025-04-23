//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;
        for (int it : arr) xor_all ^= it;
        
        int set_bit = xor_all & -xor_all;
        int G1 = 0, G0 = 0;
        for (int it : arr) {
            if (it & set_bit) G1 ^= it;
            else G0 ^= it;
        }
        if (G1 < G0) return {G1, G0};
        else return {G0, G1};
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends