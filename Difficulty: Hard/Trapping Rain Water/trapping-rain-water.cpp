class Solution {
public:
    int maxWater(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int lMax = 0, rMax = 0, ans = 0;
        
        while (l < r) {
            if (arr[l] <= arr[r]) {
                lMax = max(lMax, arr[l]);
                ans += lMax - arr[l];
                l++;
            } else {
                rMax = max(rMax, arr[r]);
                ans += rMax - arr[r];
                r--;
            }
        }
        
        return ans;
    }
};