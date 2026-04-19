class Solution {
  public:
    bool isPower(int x, int y) {
        
      float a = float(log2(y)/log2(x));
      return pow(x,a)==y;
      }
};