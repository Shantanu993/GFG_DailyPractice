class Solution {
  public:
    string URLify(string &s) {
        // code here
        string ans;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int j=s.size()-1;
        while(i<=j){
            if(s[i]==' '){
                ans+="%20";
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};