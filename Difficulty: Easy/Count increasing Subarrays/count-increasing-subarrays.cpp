class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int len = 1;
        int n = arr.size();
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i] > arr[i-1])
            {
                ans += len;
                len++;
            }
            else
                len = 1;
        }
        return ans;
    }
};