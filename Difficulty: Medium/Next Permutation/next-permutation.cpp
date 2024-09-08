//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a) {
        if(a.size()<2)
            return a;
        int i=n-2;
        for(;i>=0;--i)
            if(a[i]<a[i+1])
                break;
                
        if(i<0) {
            reverse(a.begin(),a.end());
            return a;
        }
        
        int j=n-1;
        for(;j>i;--j) {
            if(a[j]>a[i]) {
                swap(a[j],a[i]);
                break;
            }
        }
        
        int l=i+1,r=n-1;
        while(l<r)
            swap(a[l++],a[r--]);
        
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends