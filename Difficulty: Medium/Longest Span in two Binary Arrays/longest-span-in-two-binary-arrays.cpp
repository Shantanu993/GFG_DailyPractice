class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
          int res=0;
        int n=(int)a1.size();
        int s=0;
        unordered_map<int,int>mp;
        mp.reserve(n);
        mp.max_load_factor(0.25);
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            s+=(a1[i]==1)+-(a2[i]==1);
            
            if(mp.count(s))
            {
                res=max(res,i-mp[s]);
            }
            else
            mp[s]=i;
            
        }
        return res;
    }
};