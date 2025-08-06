class Solution {
  public:
    // Function to find number of subarrays having
    // sum less than or equal to x.
    long long countSub(vector<int> &arr, int n, long long x)
    {
        
        // Starting index of sliding window.
        int st = 0;
     
        // Ending index of sliding window.
        int end = 0;
     
        // Sum of elements currently present
        // in sliding window.
        long long sum = 0;
     
        // To store required number of subarrays.
        long long cnt = 0;
     
        // Increment ending index of sliding
        // window one step at a time.
        while (end < n) {
     
            // Update sum of sliding window on
            // adding a new element.
            sum += arr[end];
     
            // Increment starting index of sliding
            // window until sum is greater than x.
            while (st <= end && sum > x) {
                sum -= arr[st];
                st++;
            }
     
            // Update count of number of subarrays.
            cnt += (end - st + 1);
            end++;
        }
     
        return cnt;
    }
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // Number of subarrays having sum less
        // than or equal to R.
        long long Rcnt = countSub(A, N, R);
     
        // Number of subarrays having sum less
        // than or equal to L-1.
        long long Lcnt = countSub(A, N, L - 1);
        return Rcnt - Lcnt;
    }
};