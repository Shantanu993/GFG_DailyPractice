class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        vector<int> ans;
        int curSum =0 , sum=INT_MIN;
        int sin=-1; int ein=-1; int bin=-1;
        
        for(int i =0;i<arr.size();i++){
           
            
            if(arr[i]<0){
               
                curSum=0; continue;
            }
             if(curSum==0){
                sin=i;
            }
            
            curSum+=arr[i];
            if(curSum>sum || (curSum==sum && sin==bin)){
                sum= curSum;
                bin=sin; ein=i;
            }
       
            
        }
        
        if(bin<0){ ans.push_back(-1); return ans;}
        
        for(int i=bin;i<=ein;i++){
            ans.push_back(arr[i]);
            
        }
        return ans;
    }
};