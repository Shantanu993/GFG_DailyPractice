class Solution {
  public:
    // Fills Z array for given string str[]
    void getZarr(string str, int Z[]) {
        int n = str.length();
        int L, R, k;

        // [L,R] make a window which matches with prefix of s
        L = R = 0;
        for (int i = 1; i < n; ++i) {
            // if i>R nothing matches so we will calculate.
            // Z[i] using naive way.
            if (i > R) {
                L = R = i;

                // R-L = 0 in starting, so it will start
                // checking from 0'th index
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            } else {
                // k = i-L so k corresponds to number which
                // matches in [L,R] interval.
                k = i - L;

                // if Z[k] is less than remaining interval
                // then Z[i] will be equal to Z[k].
                if (Z[k] < R - i + 1)
                    Z[i] = Z[k];

                // L is 0
                else {
                    // else start from R and check manually
                    L = i;
                    while (R < n && str[R - L] == str[R])
                        R++;
                    Z[i] = R - L;
                    R--;
                }
            }
        }
    }

    vector<int> search(string &txt, string &pat) {
        vector<int> res;
        string concat = pat + "$" + txt;
        int l = concat.length();

        // Construct Z array
        int Z[l] = {0};
        getZarr(concat, Z);

        // now looping through Z array for matching condition
        for (int i = 0; i < l; ++i) {
            // if Z[i] (matched region) is equal to pattern
            // length we got the pattern
            if (Z[i] == pat.length())
                res.push_back(i - pat.length() - 1);
        }
        return res;
    }
};