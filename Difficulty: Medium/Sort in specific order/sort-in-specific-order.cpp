class Solution {
  public:
    void sortIt(vector<int>& arr) {
           int n =arr.size();
           sort(arr.rbegin(),arr.rend());
            int odd =0;
            for(int i=0;i<n;i++){
                  if (arr[i]%2!=0){
                      swap(arr[i],arr[odd]);
                      odd++;
                  }
                
            }
            sort(arr.begin()+odd , arr.end());
            
    }
};