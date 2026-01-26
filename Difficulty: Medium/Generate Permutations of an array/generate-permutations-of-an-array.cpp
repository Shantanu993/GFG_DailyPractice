class Solution {
  public:
    void f(int i, vector<int>& arr, vector<vector<int>>& ans){
        if(i==arr.size()){
            ans.push_back(arr);
        }
        
        for(int j = i;j<arr.size();j++){
            swap(arr[i], arr[j]);
            f(i+1, arr, ans);
            swap(arr[i], arr[j]);
        }
    }
    
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> ans;
        f(0, arr, ans);
        return ans;
    }
};