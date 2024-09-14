//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void pf(vector<int> arr, int n,vector<int>&v,int sum,int index)
    {
        if(index>=arr.size()){
            v.push_back(sum);
            return;
        }
        int element=arr[index];
        pf(arr,n,v,sum+element,index+1);
        pf(arr,n,v,sum,index+1);
        
        
    }
    vector<int> subsetSums(vector<int> arr, int n) 
    {
        vector<int>v;
        int index=0;
        int sum=0;
        pf(arr,n,v,sum,index);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends