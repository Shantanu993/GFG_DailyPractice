class cmp {
  public:
    bool operator()(const string &s1, const string &s2) {
        return s1 + s2 > s2 + s1;
    }
    
};

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        // convert all int numbers into string
        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            
            string s = "";
            
            int val = arr[i];
            if(val == 0) s = "0";
            
            while(val) {
                char dig = val % 10 + '0';
                s = dig + s;
                val /= 10;
            }
            
            v[i] = s;
        }
        
        // Sort in order to get maximum number string
        sort(v.begin(), v.end(), cmp());
        
        string ans = "";
        for(int i = 0; i < n; i++) ans += v[i];
        
        char firstDig = ans[0];
        if(firstDig == '0') return "0"; // 0000.. -> "0"
      
        return ans;
    }
};