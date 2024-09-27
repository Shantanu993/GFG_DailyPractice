//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int longestUniqueSubsttr(string s)
    {
        int start = 0, end = 0, ans = 0;
        
        vector<bool>alpha(26,0);
        
        while(start <= s.size()-1)
        {
            if(alpha[s[start]-'a'])
            {
                alpha[s[end++]-'a'] = 0;
            }
            else
            {
                alpha[s[start]-'a'] = 1;
                ans = max(ans,start-end+1);
                start++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends