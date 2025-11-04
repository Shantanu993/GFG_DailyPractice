class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if(n == 1) return 0;
        int prev = 0;
        int prev2 = 0;
        for(int i = 1; i < n; i++){
            int jump1 = prev + abs(height[i] - height[i-1]);
            int jump2 = INT_MAX;
            if(i > 1){
                jump2 = prev2 + abs(height[i] - height[i-2]);
            }
            int cur = min(jump1, jump2);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};