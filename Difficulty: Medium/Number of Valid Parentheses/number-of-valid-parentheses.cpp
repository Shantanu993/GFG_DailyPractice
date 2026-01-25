class Solution {
  public:
    virtual int fun(int n, int sum){
      if(sum<0) return 0;
      if(n==0){
        if(sum==0) return 1;
        return 0;
      }
      
      return fun(n-1, sum+1) + fun(n-1, sum-1);
    }
   
    virtual int findWays(int n){
      return (n&1)? 0: fun(n, 0);
    }
};

