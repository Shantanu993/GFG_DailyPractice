class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt = 0;
        sort(arr.begin() , arr.end());
        for(int i = 0 ; i<n ; ++i){
            for(int j = i+1 ; j<n ; ++j){
                int pos = j;
                int l = j+1 , h = n-1;
                while(l<=h){
                    int m = l + (h-l)/2;
                    
                    if(arr[m] < arr[i]+arr[j]){
                        pos = m;
                        l = m+1;
                    }else{
                        h = m-1;
                    }
                }
                
                cnt+=pos-j;
            }
        }
        
        return cnt;
    }
};