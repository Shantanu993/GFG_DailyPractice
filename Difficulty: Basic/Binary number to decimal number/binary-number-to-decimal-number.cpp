class Solution {
  public:
    int binaryToDecimal(string &b) {
        int c=0;
        int num=0;
       for(int c:b){
        num=num*2+(c-'0');
        }
      return num;  
    }
};