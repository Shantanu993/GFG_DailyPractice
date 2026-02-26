class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n = s1.length();
        vector<int> f1(26, -1), f2(26, 0);
        for(int i = 0; i < n; i++) {
            if(f1[s1[i] - 'a'] == -1 && f2[s2[i] - 'a'] == 0) f1[s1[i] - 'a'] = (s2[i] - 'a');
            else if(f1[s1[i] - 'a'] != s2[i] - 'a') return false;
            f2[s2[i] -'a'] = 1;
        }
        return true;
    }
};