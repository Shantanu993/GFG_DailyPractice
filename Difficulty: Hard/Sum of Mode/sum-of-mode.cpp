class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;
        multiset<pair<int,int>> st;
        auto insertFreq = [&](int val) {
            int old = freq[val];
            if (old > 0) st.erase(st.find({-old, val}));
            freq[val]++;
            st.insert({-freq[val], val});
        };
        auto eraseFreq = [&](int val) {
            int old = freq[val];
            st.erase(st.find({-old, val}));
            freq[val]--;
            if (freq[val] > 0) st.insert({-freq[val], val});
        };
        long long ans = 0;
        for (int i = 0; i < k; i++) insertFreq(arr[i]);
        ans += st.begin()->second;
        for (int i = k; i < n; i++) {
            insertFreq(arr[i]);
            eraseFreq(arr[i-k]);
            ans += st.begin()->second;
        }
        return (int)ans;
    }
};