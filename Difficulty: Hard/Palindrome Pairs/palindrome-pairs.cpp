class Solution{   
  public:
  bool isPalindrome(string s){
      int i=0;
      int j=s.size()-1;
      while((i<=j)){
      if(s[i]!=s[j]){
          return false;
      }
      i++;
      j--;
  }
  return true;
  }
    bool palindromepair(int N, string arr[]) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j && arr[i][0]==arr[j][arr[j].size()-1]){
              if(isPalindrome(arr[i]+arr[j])){
                        return true;
                    }
                }
        }
        }
        return false;
}
};