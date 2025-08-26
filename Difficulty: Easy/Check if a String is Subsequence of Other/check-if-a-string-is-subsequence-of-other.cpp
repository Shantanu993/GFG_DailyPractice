class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
       int n = s2.size();
       int i=0,j=0;
       while(j<n){
           if(s1[i] == s2[j])
               i++;
            j++;
       }
       return i == s1.size();
    }
};