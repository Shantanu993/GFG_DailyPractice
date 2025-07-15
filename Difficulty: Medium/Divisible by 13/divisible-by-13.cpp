class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            num = num * 10 + (s[i] - '0');
            if (num >= 13) {
                num = num % 13;
            }
        }
        return num == 0;
}
};