class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        queue<int>q;
        set<int>st;
        for(int i = 0 ; i<n ; i++){
            if(arr[i] == 'P') q.push(i) , st.insert(i);
        }
        int maxi = 0;
        for(int i = 0 ; i<n ; ){
            if(st.count(i)){ 
                i++;
                continue;
                
            } // its police index
            
            if(q.empty()) break;
            
            if(abs(i - q.front()) <= k){ 
                maxi++ ; 
                i++ ;
                q.pop();
            }
            else{
                if(q.front() < i) q.pop(); // police index is before theift and dist > k . try for another police to catch in sem queue
                else if(q.front() > i){
                    i++ ; 
                } // thift index is before police , may be police can catch another thift of less index , no police romoval
            }
        }
        return maxi;
        
    }
};