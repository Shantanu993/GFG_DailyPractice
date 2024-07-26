//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int isValid(string s) {
        // code here
        int n = s.size();
        stack<int> st;
        
        string res = "";
        for(int i=0;i<=n;i++){
            if(s[i] == '.' || s[i] == '\0'){
                int num = 0;
                for(int j=0;j<res.size();j++){
                    int temp = res[j] - '0';
                    // cout << temp << endl; 
                    num = num*10 + temp;
                }
                
              //  cout << num <<endl ;
    
                st.push(num);
                res = "";
            }
            else{
                res+=s[i];
            }
        }
        
     //   cout << st.size() << endl ;
        if(st.size() == 4){
            while(!st.empty()){
                int tp = st.top();
              //   cout<< tp << endl ;
                if(tp < 0 || tp > 255){
                    return false;
                }
                st.pop();
            }
        }
        else{
            return false;
        }
        
        if(st.size()==0) return true;
          return false;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends