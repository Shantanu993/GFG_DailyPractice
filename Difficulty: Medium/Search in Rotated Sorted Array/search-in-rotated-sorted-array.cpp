//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& n, int t) {
        // complete the function here
        int s=0,e=n.size()-1;
        while(s<=e){
            int m=(s+e)/2;
            if(n[m]==t){
                return m;
                }
            if(n[m]<n[e]){
                if(n[m]<=t && t<=n[e]){
                    s=m+1;
                    }
                else{
                    e=m-1;
                    }
                
                }
            else {
                if(n[s]<=t&& t<=n[m]){

                    e=m-1;

                    }
                else{
                    s=m+1;
                        }
                       

                
                
                }
            }
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends