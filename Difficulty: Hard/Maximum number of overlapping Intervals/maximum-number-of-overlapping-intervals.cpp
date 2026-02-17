class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int maxi = 0;
        int maxoverlap = 0;
        for(vector<int> v : arr)
        {
            maxi = max({maxi,v[0],v[1]});
        }
        vector<int> temp(maxi+5,0);
        for(auto it: arr)
        {
            temp[it[0]]++;
            temp[it[1]+1]--;
        }
        for(int i = 1;i<temp.size();i++)
        {
            temp[i] = temp[i] + temp[i-1];
            maxoverlap = max(maxoverlap,temp[i]);
        }
        
        return maxoverlap;
    }
};