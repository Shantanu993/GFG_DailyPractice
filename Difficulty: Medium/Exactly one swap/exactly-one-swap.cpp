class Solution {
  public:
     long long countStrings(string S)
    {
        // code here
        int n=S.size();
        vector<int>count(26);
        for(int i=0;i<n;i++){
            count[S[i]-'a']++;
        }
        long long int ans=0;
        bool flag=0;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                if(count[i]>1 && flag==0){
                    ans++;
                    flag=1;
                }
                ans+=1ll*(n-count[i])*count[i];
                n-=count[i];
            }
        }
        return ans;
    }
};
