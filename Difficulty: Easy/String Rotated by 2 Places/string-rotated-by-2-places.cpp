//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    
    void rotateanti(string &s){
        int x = s[0];
        int i = 1;
        
        while(i<s.size()){
            s[i-1] = s[i];
            i++;
        }
        s[s.size()-1] = x;
    }
    
    void rotateclockwise(string &s){
        int x = s[s.size()-1];
        int i = s.size() - 2;
        while(i>=0){
            s[i+1] = s[i];
            i--;
        }
        s[0] = x;
    }
    
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size() != str2.size()){
            return 0;
        }
        
        string clockwise, anticlock;
        
        clockwise = str1;
        rotateclockwise(clockwise);
        rotateclockwise(clockwise);
        if(clockwise == str2){
            return 1;
        }        
        
        anticlock = str1;
        rotateanti(anticlock);
        rotateanti(anticlock);
        if(anticlock == str2){
            return 1;
        }
        
        return 0;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends