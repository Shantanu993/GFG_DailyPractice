//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int LCS(string a,string b,int n){
        int ans=0;
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    mat[i][j]=mat[i-1][j-1]+1;
                }
                else{
                    mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
                }
            }
        }
        return mat[n][n];
    }
    int countMin(string str){
    //complete the function here
        string rev=str;
        reverse(str.begin(),str.end());
        int n=str.length();
        int eq=LCS(str,rev,n);
        return n-eq;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends