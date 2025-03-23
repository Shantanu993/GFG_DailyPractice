//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method */
class Solution {
  public:
  bool helper(vector<int>&arr,int k,int sum,int id,int curr_num,vector<bool>&vis,int cur)
  {
      if(k==1)
      {
          return true;
      }
      if(cur==sum && curr_num>0)
      {
          return helper(arr,k-1,sum,0,0,vis,0);
      }
      for(int i=id;i<arr.size();i++)
      {
          if(!vis[i])
          {
              vis[i]=true;
            if(helper(arr,k,sum,i+1,curr_num+1,vis,cur+arr[i]))
            {
                return true;
            }
              vis[i]=false;
          }
      }
      return false;
  }
    bool isKPartitionPossible(vector<int> &arr, int k) {
       int sum=0;
       for(auto it:arr)
       {
           sum+=it;
       }
       if(k<=0 || sum%k!=0)
       {
           return false;
       }
       vector<bool>vis(arr.size(),false);
       return helper(arr,k,sum/k,0,0,vis,0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> a;
        int n;
        while (ss >> n)
            a.push_back(n);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        if (obj.isKPartitionPossible(a, k))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends