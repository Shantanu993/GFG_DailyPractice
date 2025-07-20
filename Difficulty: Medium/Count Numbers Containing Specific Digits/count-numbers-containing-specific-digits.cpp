class Solution {
  public:
    long long helper(long long a, long long b){
        long long ans = 1;
        while(b){
            if(b&1){
                b--;
                ans *= a;
            }else{
                a*=a;
                b>>=1;
            }
        }
        return ans;
    }
    int countValid(int n, vector<int>& arr) {
        // code here
        long long total = 9 * helper(10, n-1);
        long long invalid = 0;
        if(find(arr.begin(), arr.end(), 0)!=arr.end()){
            invalid = helper((10-arr.size()), n);
        }else{
            invalid = (10-arr.size()-1)*helper(10-arr.size(), n-1);
        }
        return total - invalid;
    }
};