class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_map<int, int>val;
        for(int i=0;i <M;++i) {
            val[B[i]]=i+1;
        }
        vector<int>grp;
        for (int i=0;i< N;++i) {
            int num=A[i];
            if (val.find(num)!=val.end()) {
                int idx =val[num];
                auto it=lower_bound(grp.begin(),grp.end(),idx);
                if (it==grp.end()) 
                    grp.push_back(idx);
                else 
                    *it=idx;
            }
        }
        int l =grp.size();
        int end=N-l;
        int start= M-l;
        return end+start;
    }
};