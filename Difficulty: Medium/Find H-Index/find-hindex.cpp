class Solution {
  public:
  int check(int mid,vector<int>&citations)
  {
      int count=0;
      for(int i=0;i<citations.size();i++)
      {
          if(citations[i]>=mid)count++;
      }
      return count;
  }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=1,h=n;
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(check(mid,citations)>=mid)
            {
                ans=mid;
                l=mid+1;
            }
            else if(check(mid,citations)<mid)
            {
                h=mid-1;
            }
        }
        return ans;
    }
};