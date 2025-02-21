//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
     void find(int index,string &s,vector<string>&v)
   {
       if(index==s.size())
       {
           v.push_back(s);
           return;
       }
       for(int i=index;i<s.size();i++)
       {
           swap(s[index],s[i]);
           find(index+1,s,v);
           swap(s[index],s[i]);
       }
   }
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string>v;
        find(0,s,v);
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends