#include <cmath>

using namespace std;

class Solution {
  public:
    int helper(int last, int visited, vector<vector<int>>& cost, int max_visited, vector<vector<int>>& dp) {
        if(visited == max_visited)
            return cost[last][0];
            
        if (dp[last][visited] != -1)
            return dp[last][visited];
        
        int mini = INT_MAX;
        for(int i = 0; i < cost.size(); i++) {
            if ((visited & (1 << i)) == 0) {
                mini = min(mini, cost[last][i] + helper(i, visited | 1 << i, cost, max_visited, dp));
            }
        }
        
        dp[last][visited] = mini;
        
        return mini;
    }
    
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int max_visited = pow(2, cost.size()) - 1;
        vector<vector<int>> dp(n, vector<int>(max_visited, -1));
        return helper(0, 1, cost, max_visited, dp);
    }
};