class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int ans = 0;
        int l = 0, r = n;
        for(int i : left)   ans = max(ans, i - l);
        for(int i : right)   ans = max(ans, r - i);
        return ans;
    }
};