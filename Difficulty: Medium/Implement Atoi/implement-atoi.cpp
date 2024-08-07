//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int n = s.size();
        if(s=="") return 0;
        int res = 0;
        int sign = 1;
        int i = 0;
        if(s[0]=='-'){
            sign = -1;
            i++;
        }
        for(; i<n; ++i){
            if(isdigit(s[i])==false) return -1;
            res = res*10 + s[i] - '0';
            
        }
        return sign*res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends