//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution
{
    public:
    //Function to find the largest number after k swaps.
   vector<int> maxIdxs(string& S, int l, int r){
        char maxVal=S[l];
        for(int i=l+1;i<=r;i++){
            if(S[i]>maxVal){
                maxVal=S[i];
            }
        }
        
        vector<int> rst;
        if(S[l]==maxVal){
            return rst;
        }
        else{
            for(int i=l+1;i<=r;i++){
                if(S[i]==maxVal){
                    rst.push_back(i);
                }
            }
        }

        return rst;
    }

    void findRange(string& str, string& rst, int l, int r, int k)
    {
       if(k==0 || l==r){
            if(str>rst){
                rst=str;
            }
            return;
       } 

       vector<int> idxs=maxIdxs(str,l,r);
       if(idxs.empty()){
            findRange(str, rst, l+1, r, k);
       }
       else{
            for(int i=0;i<idxs.size();i++){
                swap(str[l],str[idxs[i]]);
                findRange(str, rst, l+1, r, k-1);
                swap(str[l],str[idxs[i]]);
            }
       }
    }


    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string rst=str;
       int l=0;
       int r=str.size()-1;
       findRange(str, rst, l, r, k);
       return rst;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends