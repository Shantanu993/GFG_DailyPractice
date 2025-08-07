// User function Template for C++

class Solution {
  public:
     int longestSubstring(string s) {
      map<int,int>m;
      int mask=0;
      for(int i=0;i<s.size();i++){
          mask^=(1<<(s[i]-'a'));
          m[mask]=i;
      }
     int mx=0;
      mask=0;
      for(int i=0;i<s.size();i++){
          mask^=(1<<(s[i]-'a'));
          int id=m[mask];
          int len=(id-i);
          mx=max(mx,len);
          for(int j=0;j<26;j++){
              if((mask^(1<<(j)))>=mask){
                  int val=mask;
                  val^=(1<<j);
                  int index=m[val];
                  int l=(index-i);
                  if(l>0) mx=max(mx,l);
              }
              else{
                  int val=mask;
                  val^=(1<<j);
                  if(m.find(val)!=m.end()){
                      int l=m[val];
                      mx=max(mx,l-i);
                  }
              }
          }
      }
     
      if(m.find(0)!=m.end()){
          mx=max(mx,m[0]+1);
      }
      
      for(int i=0;i<26;i++){
          int val=(1<<i);
          if(m.find(val)!=m.end()){
              mx=max(mx,m[val]+1);
          }
      }
              
        
        return mx;

}
};