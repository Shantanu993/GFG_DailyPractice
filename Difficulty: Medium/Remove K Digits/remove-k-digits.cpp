class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        stack<char>st;  // stack to keep the monotaonic chars
        int count =0;
        for(auto i: s){
            while(!st.empty() && st.top() > i && count<k){
                st.pop();
                count++;
            }
            if(st.empty() && i=='0')continue; // to ignore the leading 0s
            st.push(i);
            
        }
        string ans = "";
        while(count<k && !st.empty()){   // if there are still k' removals left
            st.pop();
            count++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());  // reverse the string as stack pushes the elements rigth through left.
        if(ans.size() ==0)return "0";  // if no elements then ans = 0
        return ans;
        
    }
};