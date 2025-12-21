class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            if (!mp.count(x)) {
                ans.push_back(0);
                continue;
            }

            auto &v = mp[x];
            int left = lower_bound(v.begin(), v.end(), l) - v.begin();
            int right = upper_bound(v.begin(), v.end(), r) - v.begin();

            ans.push_back(right - left);
        }

        return ans;
    }
};