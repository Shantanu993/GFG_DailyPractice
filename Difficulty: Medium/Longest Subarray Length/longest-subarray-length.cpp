class Solution {
  public:
  
  vector<int>nextgreater(vector<int>&arr){
      int n=arr.size();
      vector<int>ans(n,n);
      stack<int>st;
      for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()]<=arr[i]){
              st.pop();
          }
          if(!st.empty()){
              ans[i]=st.top();
          }
          st.push(i);
      }
      
      return ans;
  }
  vector<int>previousgreater(vector<int>&arr){
      int n=arr.size();
         vector<int>ans(n,-1);
      stack<int>st;
      for(int i=0;i<n;i++){
          while(!st.empty() && arr[st.top()] <=arr[i]){
              st.pop();
          }
         if(!st.empty()){
             ans[i]=st.top();
         }
         st.push(i);
          
      }
      return ans;
  }
  
      int longestSubarray(vector<int>& arr) {
       vector<int>nGe=nextgreater(arr);
        vector<int>pGe=previousgreater(arr);
        int maxl=0;
        for(int i=0;i<arr.size();i++){
            int curr=nGe[i]-pGe[i]-1;
            if(curr>=arr[i]){
                maxl=max(maxl,curr);
            }
            
        }
        return maxl;
        
    }
};