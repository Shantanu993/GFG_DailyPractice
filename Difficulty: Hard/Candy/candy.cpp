class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        vector<int> candies(n, 1);  // Step 1: Initialize with 1 candy

        // Step 2: Left to Right
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum up the candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }
        return total;
    }
};

