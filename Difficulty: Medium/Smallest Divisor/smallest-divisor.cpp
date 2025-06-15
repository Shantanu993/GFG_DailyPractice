class Solution {
  public:
  
    int helper(vector<int> &arr , int num){
        int res = 0;
        for(auto it:arr){
            res += (it / num) + (it%num != 0);
        }
        
        return res;
    }
    
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1;
        int r = *max_element(arr.begin(),arr.end());
        int ans = r;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            int temp = helper(arr,mid);
            if(temp <= k){
                ans = min(ans,mid);
                r = mid - 1;
            }else if(temp > k){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        return ans;
    }
};