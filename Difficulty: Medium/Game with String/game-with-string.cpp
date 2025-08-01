class Solution {
  public:
    int minValue(string &s, int k) {
        int hash[26] = {0};
        for(auto i : s){
            hash[i - 'a']++;
        }
        sort(hash, hash+26);
        
        int ans = 0, rem = s.size()-k;
        for(int i=0, n=26;i<26;i++,n--){
            int mn = min(hash[i], rem/n);
            ans += mn*mn;
            rem -= mn;
        }
        return ans;
    }
};