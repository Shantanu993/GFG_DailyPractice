//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod=1e9+7;
    int countWays(int n)
    {
        // your code here
        if(n==1) return 1;
        int a=1;
        int b=1;
        int c;
        
        for(int i=2;i<=n;i++)
        {
            c=(a+b)%mod;
            b=a;
            a=c;
        }
        return c;
    }
};




//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends