class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i=0, ctr=0, ans=0;
        
        for (int j=0; j<n; j++) {
            int w_size = j-i+1;
            if (arr[j]==0) {
                ctr++;
                while (ctr>k) {
                    if(arr[i]==0) ctr--;
                    i++;
                    w_size--;
                }
            }
            // cout << w_size << ' ';
            ans = max(ans, w_size);
        }
        // cout << '\n';
        return ans;
    }
};