class Solution {
  public:
    int minParentheses(string& s) {
        stack<int> o,c;
        
        for(auto it:s){
            if(it=='(') o.push(it);
            else{
                if(o.empty()) c.push(it);
                else o.pop();
            }
        }
        
        return c.size()+o.size();
    }
};