//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
    int K,N; //variables to store the number of digits (N) and the base number (K)
    long long tot; //variable to store the total number of possible strings
    set<string> st; //set to store the generated strings
    //Function to perform depth-first search to generate all possible strings
    bool dfs(string &ans){
        if(st.size()==tot){ //if all possible strings are generated, return true
            return true;
        }
        string tmp="";
        if(N>1){
            tmp=ans.substr(ans.size()-N+1); //get the last N-1 digits of the current string
        }
        
        for(int i=0;i<K;i++){ //for each possible digit
            tmp.push_back((char)(i+'0')); //add the digit to the last N-1 digits
            if(st.find(tmp)==st.end()){ //if the newly generated string is not already in the set
                ans.push_back(char(i+'0')); //add the digit to the current string
                st.insert(tmp); //insert the newly generated string to the set
                if(dfs(ans)) //recursively call dfs function
                    return true;
                st.erase(tmp); //remove the newly generated string from the set
                ans.pop_back(); //remove the added digit from the current string
            }
            tmp.pop_back(); //remove the added digit from the last N-1 digits
        }
        return false;
    }
    //Function to find the lexicographically smallest string of length N using K digits
    string findString(int n, int k) {
        K=k;
        N=n;
        st.clear(); //clear the set
        if(n==1){
            string r="";
            for(int i=0;i<k;i++)
                r.push_back((char)(i+'0')); //if N=1, return a string of all digits from 0 to K-1
            return r;
        }
        tot=1;
        for(int i=1;i<=n;i++)
            tot=(tot*k); //calculate total number of possible strings
        string ans=string(n,'0'); //initialize current string with all zeros
        st.insert(ans); //insert the current string to the set
        dfs(ans); //call dfs function to generate all possible strings
        return ans; //return the lexicographically smallest string
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
} 
// } Driver Code Ends