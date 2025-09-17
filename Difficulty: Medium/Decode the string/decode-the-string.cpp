class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]==']'){
                string temp_str = "";
                while(st.top()!='['){
                    temp_str += st.top();
                    st.pop();
                }
                reverse(temp_str.begin(),temp_str.end());
                st.pop();
                
                string num_str = "";
                while(!st.empty() && isdigit(st.top())){
                    num_str += st.top();
                    st.pop();
                }
                reverse(num_str.begin(),num_str.end());
                int num = stoi(num_str);
                
                for(int i=0; i<num; i++){
                    for(auto& c : temp_str){
                        st.push(c);
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};