class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = accumulate(arr.begin(), arr.begin() + k, 0);
        int ans = sum;
        
        for(int i = k; i < (int)arr.size(); i++){
            sum = sum + arr[i] - arr[i - k];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};