class Solution {
  public:
    
     vector<string>ans;
     
     void solve(int n,string &curr){
            if (curr.size()==n){
                 ans.push_back(curr);
                 return ;
            }
            
               for(int i='0';i<='1';i++){
                     curr.push_back(i);
                     solve(n,curr);
                     curr.pop_back();
               }
               
            
            
           
     }
    vector<string> binstr(int n) {
           
           
            string curr ="";
            
            solve(n,curr);
            return ans;
        
    }
};