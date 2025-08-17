//Back-end complete function template in C++

class Solution {
  public:
    // Helper function to build expressions
    void buildExpr(vector<string>& res, string expr, string digits, int target, int idx,
                   long long eval, long long last) {

        if (idx == digits.length()) {
            if (eval == target)
                res.push_back(expr);
            return;
        }

        for (int i = idx; i < digits.length(); i++) {

            // Skip numbers with leading zero
            if (i != idx && digits[idx] == '0')
                break;

            string part = digits.substr(idx, i - idx + 1);
            long long num = stoll(part);

            if (idx == 0) {
                buildExpr(res, part, digits, target, i + 1, num, num);
            } else {
                buildExpr(res, expr + "+" + part, digits, target, i + 1, eval + num,
                          num);
                buildExpr(res, expr + "-" + part, digits, target, i + 1, eval - num,
                          -num);
                buildExpr(res, expr + "*" + part, digits, target, i + 1,
                          eval - last + last * num, last * num);
            }
        }
    }

    // Function to return expressions evaluating to the target
    vector<string> findExpr(string& s, int target) {
        vector<string> res;
        buildExpr(res, "", s, target, 0, 0, 0);
        return res;
    }
};