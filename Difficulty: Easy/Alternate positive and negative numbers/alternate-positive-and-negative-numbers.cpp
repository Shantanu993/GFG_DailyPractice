//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int n=arr.size()-1;
        vector<int>fir;
        vector<int>sec;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] < 0){
                fir.push_back(arr[i]);
            }
            else{
                sec.push_back(arr[i]);
            }
        }
        arr.clear();
        int i = 0, j = 0;
        while (i < sec.size() && j < fir.size()) {
            arr.push_back(sec[i++]);  // Add a positive element
            arr.push_back(fir[j++]);  // Add a negative element
        }
        while (i < sec.size()) {
            arr.push_back(sec[i++]);
        }
        while (j < fir.size()) {
            arr.push_back(fir[j++]);
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends