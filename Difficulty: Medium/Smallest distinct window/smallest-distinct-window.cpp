//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSubString(string& s) {
        // Your code goes here
        int u_count = 0;
        int unique[256] = {0};
        for (int s1 : s) 
        {
           if (unique[s1] == 0) 
           {
               u_count++;
            }
            unique[s1]++;
        }

        int min_len = INT_MAX;
        int freq[256] = {0};
        int count = 0;
        int start = 0;
        for (int end = 0; end < s.length(); end++) 
        {  
           freq[s[end]]++;
           if (freq[s[end]] == 1) 
           {
              count++;
            }
            while (count == u_count) 
            {
                min_len = min(min_len, end - start + 1);
                freq[s[start]]--;
                if (freq[s[start]] == 0) 
                {
                   count--;
                }
                start++;
            }
        } 
    return  min_len;
    }
    
     
};


//{ Driver Code Starts.
//   Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends