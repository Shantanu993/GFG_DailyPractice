class Solution {
  public:// check function to check different string values of  '*'
      bool check(string &pat , string &txt , int i , int j){
         int n = pat.size() , m = txt.size();
          int x = i , y = j;
          while(x<n && (pat[x]=='*' || pat[x] =='?')){
              if(pat[x] == '?')y++;
              x++;
          } 
          if(y>m)return false;
         if(x==n){
              return true;
          }else{
              bool k = false;
              for(; y<m;y++){
                  
                  if(txt[y] == pat[x]){
                      string temp1 = txt.substr(y) , temp2 = pat.substr(x); 
                      k= wildCard(temp1 ,temp2 );
                   }
                  if(k)return true;
              }
          }
          return false;
          
           
       }
    bool wildCard(string &txt, string &pat) {
        // code here
        int i=0 , j =0;
        while(i<pat.size() && j<txt.size()){
            if(pat[i]=='?'){
                i++;
                j++;
            }else if(pat[i] == '*'){
                return check(pat , txt , i , j);
            }else{
                if(pat[i]!=txt[i])return false;
                else{
                    i++;
                    j++;
                }
            }
        } 
        while(i< pat.size() && (pat[i]=='*' )){
              i++;
          } 
        if(i != pat.size() || j!= txt.size())return false;
        return true;
    }
};