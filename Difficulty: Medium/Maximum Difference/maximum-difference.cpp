//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int ans=0;
        vector<int> ls;
        vector<int> rs(arr.size());
        stack<int> st;
        
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty())  ls.push_back(0);
            else{
                ls.push_back(st.top());
            }
            st.push(arr[i]);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty())  rs[i]=0;
            else{
                rs[i]=(st.top());
            }
            st.push(arr[i]);
        }
        
        for(int i=0;i<arr.size();i++){
            if(abs(ls[i]-rs[i])>ans){
                ans=abs(ls[i]-rs[i]);
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

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends