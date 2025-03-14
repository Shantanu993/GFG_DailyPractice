//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    
    int rec(vector<int> & coins,int currsum,int curridx
    ,vector<vector<int>>& dp
    ){
        if(currsum<0){
            return 0;
        }
        if(currsum==0){
            return 1;
        }
        
        if(dp[currsum][curridx]!=-1){
            return dp[currsum][curridx];
        }
        dp[currsum][curridx] = 0;
        
        for(int i = curridx;i<coins.size();i++){
            if(currsum-coins[i]>=0 && dp[currsum-coins[i]][i]!=-1){
                dp[currsum][curridx]+=dp[currsum-coins[i]][i];
            }else{
                dp[currsum][curridx] += rec(coins,currsum-coins[i],i,dp);
            }
        }
        return dp[currsum][curridx];
    }
    
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<vector<int>> dp(sum+1,vector<int>(coins.size(),-1));
        sort(coins.begin(),coins.end());
        return rec(coins,sum,0 ,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends