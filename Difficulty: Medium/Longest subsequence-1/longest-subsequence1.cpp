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


class Solution {
  public:
  
  void print(vector<int> &nums){
      for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
      cout<<endl;
  }
  
    int longestSubseq(int n, vector<int> &nums) {
        int maxlen = 0, res = 0;
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++){
            int num = nums[i], maxi = 0;
            for(int j=i-1;j>=0;j--){
                //cout<<num<<" : "<<nums[j]<<endl;
                if(abs(num - nums[j])==1) maxi = max(dp[j],maxi); 
            }
            //cout<<endl;
            
            dp[i] = maxi + 1;
            res = max(res,dp[i]);
        }
        
        //print(dp);
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends