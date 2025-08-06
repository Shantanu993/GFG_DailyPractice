class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int>um;
        um['I']=1;
        um['V']=5;
        um['X']=10;
        um['L']=50;
        um['C']=100;
        um['D']=500;
        um['M']=1000;
        int prev = 10000,ans=0 ;
        for(char i:s){
            ans+=um[i];
            if(prev<um[i])ans-=2*prev;
            prev=um[i];
        }
        return ans;
    }
};