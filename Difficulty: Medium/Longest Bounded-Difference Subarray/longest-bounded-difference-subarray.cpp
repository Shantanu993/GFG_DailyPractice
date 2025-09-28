class Solution {
  public:
    vector<int> longestSubarray(vector<int>& nums, int x) {
        // code here
        int n=nums.size();
        int temp=0;
        int sans=0;
        int eans=0;
         priority_queue<pair<int,int>>pqmax;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pqmin;
         for(int i=0;i<n;i++)
         {
             while(!pqmax.empty() && abs(pqmax.top().first-nums[i])>x)
             {
                 temp=max(temp,pqmax.top().second+1);
                 pqmax.pop();
             }
             while(!pqmin.empty() && abs(pqmin.top().first-nums[i])>x)
             {
                 temp=max(temp,pqmin.top().second+1);
                 pqmin.pop();
             }
             if(i-temp+1>eans-sans+1)
             {
                 sans=temp;
                 eans=i;
             }
              pqmax.push({nums[i],i});
              pqmin.push({nums[i],i});
         }
         vector<int>flag;
         for(int i=sans;i<=eans;i++)
         {
             flag.push_back(nums[i]);
         }
         return flag;
        
    }
};