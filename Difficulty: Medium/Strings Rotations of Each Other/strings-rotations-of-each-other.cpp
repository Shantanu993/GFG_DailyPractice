//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string& s1, string& s2) {
       int n=s1.length();
       //s1 pattern
       vector<int> lps(n,0);
       int len=0;
       int i=1;
       while(i<n){
           if(s1[i]==s1[len]){
               len++;
               lps[i]=len;
               i++;
           }
           else{
               if(len!=0){
                   len=lps[len-1];
               }
               else{
                   lps[i]=0;
                   i++;
               }
           }
       }
       s2=(s2+s2);
       //i chlega 
       i=0;
       int j=0;
       while(i<2*n){
           if(s2[i]==s1[j]){
               i++;
               j++;
           }
           if(j==n){
               return true;
           }
           else if(s1[j]!=s2[i]){
               if(j!=0){
                   j=lps[j-1];
               }
               else{
                   i++;
               }
           }
       }
       return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.areRotations(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends