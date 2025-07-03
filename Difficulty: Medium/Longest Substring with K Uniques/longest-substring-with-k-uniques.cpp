class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<int,int>mp;
        int j = 0, n = s.length(), ans = -1;
        for (int i=0; i<n; i++){
            mp[s[i] - 'a']+=1;
            while (j <= i && mp.size() > k){
                mp[s[j]-'a']-=1;
                if (mp[s[j]-'a'] == 0) mp.erase(s[j]-'a');
                j++;
            }
            if (mp.size() == k) ans = max(ans, i - j + 1);
        }
        return ans;
    }
};