class Solution{
public:
    bool recreationalSpot(int nums[], int n){
        stack<int> st;
        int flag=INT_MIN;
        for(int i=n-1; i>=0 ; --i){
            if(nums[i]<flag)
                return true;
            while(!st.empty() && st.top()<nums[i]){
                flag=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};