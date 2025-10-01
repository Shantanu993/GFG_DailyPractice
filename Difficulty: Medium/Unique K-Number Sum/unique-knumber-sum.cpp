class Solution
{
public:
  void solve(int idx, int sum, vector<int> &arr, int k, vector<vector<int>> &result, vector<int> &ans)
  {
    if (idx == arr.size())
    {
      if (sum == 0 && k == 0)
      {
        result.push_back(ans);
      }
      return;
    }
    if (idx >= arr.size() || sum < 0)
      return;
    //   int pick=0,notpick=0;
    //   if(arr[idx]<=sum){
    ans.push_back(arr[idx]);
    solve(idx + 1, sum - arr[idx], arr, k - 1, result, ans);
    //   }
    //   else{
    ans.pop_back();
    solve(idx + 1, sum, arr, k, result, ans);
    //   }
  }
  vector<vector<int>> combinationSum(int n, int k)
  {
    // code here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Only numbers from the range [1, 9] used.
    // Each number can only be used at most once.
    vector<vector<int>> result;
    vector<int> ans;
    solve(0, n, arr, k, result, ans);
    return result;
  }
};
