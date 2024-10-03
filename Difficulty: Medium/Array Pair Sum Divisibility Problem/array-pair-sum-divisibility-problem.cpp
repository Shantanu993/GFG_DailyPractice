//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n%2!=0){
            return 0;
        }
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int n = nums[i]%k;
            mp[n] +=1;
        }
        int sum = 0;
        int c = 0;
        for(auto it : mp){
            if(it.first == 0){
                if(it.second%2!=0){
                    return 0;
                }
            }
            else{
                
                int com = k-it.first;
                if(mp[it.first]!=mp[com]){
                    return 0;
                }    
            }
        }
        
    return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends