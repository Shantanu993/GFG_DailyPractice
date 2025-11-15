class Solution {
  public:
   vector<int> cut; 
    map<pair<int,int>, int> dp;

    int solve(int mini, int maxi) 
    {
        if (mini + 1 >= maxi) 
        {
            return 0;
        }

        if (dp.count({mini, maxi}))
        {
            return dp[{mini, maxi}];
        }

        int ans = INT_MAX;

        int i = lower_bound(cut.begin(), cut.end(), mini + 1) - cut.begin();

        while (i < cut.size() && cut[i] < maxi)
        {
            int mid = cut[i];

            int left = solve(mini, mid);
            int right = solve(mid, maxi);

            ans = min(ans, left + right + (maxi - mini));

            i++;
        }

        if (ans == INT_MAX)
        {
            ans = 0;
        }

        dp[{mini, maxi}] = ans;
        return ans;
    }


    int minCutCost(int n, vector<int>& cuts) 
    {
        sort(cuts.begin(), cuts.end());
        cut = cuts;
        dp.clear();
        return solve(0, n);
    }
};

