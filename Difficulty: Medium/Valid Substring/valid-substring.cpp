//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
     int findMaxLen(string s) {
        int l = 0;
        int r = 0;
        int maxi = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i]=='('){
                l++;
            }
            if(s[i]== ')'){
                r++;
            }
            
            if(l==r){
                maxi = max(maxi, 2*l);
            }
            if(l<r){
                l = 0;
                r = 0;
            }
        }
        //reinitialize
        l=0;
        r=0;
        for(int i = s.size()-1 ; i >= 0 ;i--){
            if(s[i]=='('){
                l++;
            }
            if(s[i]==')'){
                r++;
            }
            
            if(l==r){
                maxi = max(maxi, 2*l);
            }
            if(l>r){
                l = 0;
                r = 0;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends