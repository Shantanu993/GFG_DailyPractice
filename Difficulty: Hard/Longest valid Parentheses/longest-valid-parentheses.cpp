//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maxLength(string& str) {
        int open=0;
        int close=0;
        int ans=INT_MIN;
        
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                open++;
            }
            else{
                close++;
            }
            
            if(open<close) open=close=0;
            if(open==close) ans=max(ans,2*close);
        }
        
        open=0;
        close=0;
        
        
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]=='('){
                open++;
            }
            else{
                close++;
            }
            
            if(open>close) open=close=0;
            if(open==close) ans=max(ans,2*close);
        }
        
        return ans;
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
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends