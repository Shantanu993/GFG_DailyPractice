class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        if(n<2) return 1;
        int prev2=1,prev1=2;
        for(int i=3;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
