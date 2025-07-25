class Solution {
private:
    vector<int> solve(int n, vector<int> &arr)
    {
        int mx=arr[0], mn=arr[0], total=arr[0];
        int mxs=arr[0], mns=arr[0];
        
        for(int i=1; i<n; i++) {
            mx=max(arr[i], arr[i]+mx);
            mxs=max(mxs, mx);
            
            mn=min(arr[i], arr[i]+mn);
            mns=min(mns, mn);
            
            total+=arr[i];
        }
        
        return {mxs,mns,total};
    }
    
public:
    int maxCircularSum(vector<int> &arr) 
    {
        int n=arr.size();
        vector<int> ans = solve(n,arr);
        
        int mx=ans[0], mn=ans[1], total=ans[2];
        
        if(mx<0)
            return mx;
        return max(mx,total-mn);
    }
};