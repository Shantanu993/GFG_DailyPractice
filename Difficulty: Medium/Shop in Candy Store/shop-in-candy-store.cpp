class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        vector<int>ans;
        int n=prices.size();
        deque<int>dq;
        sort(prices.begin(),prices.end());
        for(int i=0;i<n;i++){
            dq.push_back(prices[i]);
        }
        int mini=0;
        while(!dq.empty()){
            int it=dq.front();
            mini+=it;
            dq.pop_front();
            int m=k;
            while(dq.size()>0 && m>0){
                dq.pop_back();
                m--;
            }
        }
        ans.push_back(mini);
        
        sort(prices.rbegin(),prices.rend());
        for(int i=0;i<n;i++){
            dq.push_back(prices[i]);
        }
        int maxi=0;
        while(!dq.empty()){
            int it=dq.front();
            maxi+=it;
            dq.pop_front();
            int m=k;
            while(dq.size()>0 && m>0){
                dq.pop_back();
                m--;
            }
        }
        ans.push_back(maxi);
        
        
        
        return ans;
    }
};