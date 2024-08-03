//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int celebrity(vector<vector<int> >& M) 
    { 
        int n=M.size(); 
        
        stack<int>s; 
        for(int i=0; i<n; i++){
            s.push(i); 
        }
        while(s.size()>1){
            int i=s.top();
            s.pop(); 
            int j=s.top(); 
            s.pop(); 
            if(M[i][j]){
                s.push(j); 
            }
            else{
                s.push(i); 
            }
        }
        for(int i=0; i<n; i++){
            if(i!=s.top()){
                if(M[s.top()][i] or !M[i][s.top()]){
                    return -1; 
                }
            }
        }
        
        return s.top(); 
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends