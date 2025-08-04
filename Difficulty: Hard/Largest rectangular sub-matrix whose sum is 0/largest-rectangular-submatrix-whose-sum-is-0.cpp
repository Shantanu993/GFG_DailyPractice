class Solution {
  public:
    int pfxsm(vector<int>&arr){
        unordered_map<int,int>mp;
        int mx=0, pfx=0;
        int n=arr.size();
        
        for(int  i=0;i<n;i++){
            pfx+=arr[i];
            
            // pfx =0 keep increasing;
            if(pfx==0) mx = max(mx, i+1);
            // not first occurance; pfx(j)=pfx(i-1);
            if(mp.find(pfx)!=mp.end()){
                mx= max(mx, i-mp[pfx]);
            }else{
                // ist occurance;e
                mp[pfx]=i;
            }
        }
        return mx;
    }
    int zeroSumSubmat(vector<vector<int>>& mat) {
        // Code Here
        int n =mat.size(), m=mat[0].size();
        int mxarea=0;
        for(int i=0; i<n;i++){
            vector<int>tmp(m, 0);
            for(int j=i;j<n;j++){
                // for each col  add ;
                for(int k=0; k<m;k++){
                    tmp[k]+= mat[j][k];
                }
                int l = pfxsm(tmp);
                mxarea= max(mxarea, (j-i+1)*l);
            }
        }
        
        return mxarea;
    }
};