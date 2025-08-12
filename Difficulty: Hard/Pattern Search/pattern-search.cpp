class Solution {
  public:
    // Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) {
        // Your code here
        int n1 = pat.size();
        int n2 = txt.size();
        for (int i = 0; i <= n2 - n1; i++) {
            int j;
            for (j = 0; j < n1; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == n1) return true; 
        }

        return false;
    }
};