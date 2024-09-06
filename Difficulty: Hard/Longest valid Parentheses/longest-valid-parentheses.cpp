//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int maxLength(string S){
        int ct = 0;
        int ma = 0;
        int error = 0;
        stack<int> st;
        vector<int> dp(S.size() + 1 , 0);
        for(int i = 0 ; i <S.size() ; i++){
            if(S[i] == ')' && ct == 0){
                continue;
                
            }
            if(S[i] == '('){
                st.push(i);
                ct++;}
            else{
                ct--;
           //     if(ct==0){
                    if(st.top() != 0)
                    dp[i] = i - st.top() + 1 + dp[st.top() - 1];
                    else dp[i] = i - st.top()+1;
                    ma = max(ma ,dp[i]);
               // }
             //   else ma = max(ma , i - st.top() + 1);
               
                st.pop();
                
            }
            
        }
        
        return ma;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends