//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(vector<int>& a) {
        // Your code here
        int n=a.size();
        vector<int>left(n),right(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i])
            st.pop();
        if(st.empty())
            left[i]=-1;
        else  
            left[i]=st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && a[st.top()]>=a[i])
            st.pop();
        if(st.empty())
            right[i]=n;
        else  
            right[i]=st.top();
        st.push(i);
    }
    vector<int>ans(n+1,0);
    for(int i=0;i<n;i++)
    {
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    vector<int>res(n);
    for(int i=1;i<=n;i++)
    {
        res[i-1]=ans[i];
    }
    return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMin(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends