//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        vector<long long> v(N+1, 1);
        // for(int i=1; i<=min(N, 6); i++)
        // {
        //     v[i] = i;
        // }
        for(int i=2; i<=N; i++)
        {
            long long maxx = i;
            for(int j=i-3; j>=1; j--)
            {
                // cout << j << endl;
                long long t = 1LL*(i-j-1)*v[j];
                maxx = max(t, maxx);
            }
            v[i] = maxx;
        }
        return v[N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends