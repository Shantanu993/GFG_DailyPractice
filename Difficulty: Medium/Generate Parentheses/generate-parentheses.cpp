class Solution {
  public:
    void f(vector<string> &ans, string s, int n, int o, int c) {
        if(o + c == n) {
            ans.push_back(s);
            return;
        }
        // go for opening iff it can occur at most n / 2 times
        if(o + 1 <= n / 2) f(ans, s + '(', n, o + 1, c);
        
        // go for closing iff it can occur <= opening cnt
        if(c + 1 <= o) f(ans, s + ')', n, o, c + 1);
    }
    vector<string> generateParentheses(int n) {
        vector<string> ans;
        f(ans, "", n, 0, 0);
        return ans;
    }
};