class Solution {
  public:
    vector<int> getSmaller(vector<int> arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);  // prefix small elem
        pse[0] = -1;
        st.push(0);
        for(int i = 1; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> sse(n); // suffix small elem
        sse[n-1] = -1;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            sse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int l = pse[i];
            int r = sse[i];
            
            if(l == -1 && r == -1){
                ans[i] = -1;
            }
            else if(l == -1){
                ans[i] = r;
            }
            else if(r == -1){
                ans[i] = l;
            }
            else if(abs(i-l) < abs(i-r)){
                ans[i] = l;
            }
            else if(abs(i-l) > abs(i-r)){
                ans[i] = r;
            }
            else{
                if(arr[l] <= arr[r]){
                    ans[i] = l;
                }
                else{
                    ans[i] = r;
                }
            }
        }
        
        return ans;
    }
};