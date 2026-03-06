class Solution {
  public:
    string minWindow(string &s, string &p) {
        int m=s.length(), n=p.length();
        if(m<n) return "";
        
        int minLen=1e9, left=0, start=-1, cnt=0;
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++) mp[p[i]]++;
        
        for(int right=0;right<m;right++){
            if(mp[s[right]]>0) cnt++;
            mp[s[right]]--;
            if(cnt==n){
                while(mp[s[left]]<0) {
                    mp[s[left]]++;
                    left++;
                }
                if(minLen>right-left+1){
                    minLen=right-left+1;
                    start=left;
                }
            }
        }
        return minLen==1e9?"":s.substr(start,minLen);
    }
};