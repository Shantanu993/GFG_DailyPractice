//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends



class Solution 
{
  public:
   void solve(map<int,string>mp, int ind,string str,vector<int> &arr, vector<string>&ans)
   {
       if(ind == arr.size())
       {
           ans.push_back(str);
           return;
       }
       int x = arr[ind];
       for(int i =0;i<mp[x].size();i++)
       {
           string p = mp[x];
           solve(mp,ind+1,str+p[i],arr,ans);
       }
   }
   vector<string> possibleWords(vector<int>&arr)
   {
    map<int,string>mp={
        {1,""},
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"},
    };
    vector<string>ans;
    string str="";
    int ind = 0;
    
    solve(mp,ind,str,arr,ans);
    return ans;
   }
};
    
    
    
    
    
    
    
    
    


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        vector<string> v = obj.possibleWords(a);
        sort(v.begin(), v.end());
        Array::print(v);
        cout << "~" << endl;
    }
}

// } Driver Code Ends