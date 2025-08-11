#include <vector>

class Solution {
public:
    int maxCoins(int N, vector<int> &a) {
        // Create a new vector with boundary elements and copy input array
        vector<int> nums(N + 2, 1);
        for (int i = 0; i < N; i++) {
            nums[i + 1] = a[i];
        }

        // Initialize a 2D dp array to store the maximum coins for each subarray
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));

        // Iterate over all possible subarrays
        for (int len = 2; len <= N + 1; len++) {
            for (int left = 0; left + len <= N + 1; left++) {
                int right = left + len;
                for (int last = left + 1; last < right; last++) {
                    // Choose the balloon to burst at last position in the current subarray
                    int coins = nums[left] * nums[last] * nums[right];
                    coins += dp[left][last] + dp[last][right];

                    // Update maximum coins for the current subarray
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        // The result is stored in the top-right corner of the dp array
        return dp[0][N + 1];
    }
};