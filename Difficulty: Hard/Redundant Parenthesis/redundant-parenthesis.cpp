class Solution{   
public:
    string removeBrackets(string s){    
        //code here
        string ans = "";
        int f=0;
        vector<int> v(s.size());
        stack<int> st;
        unordered_set<int> st1,st2,st3;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
                v[i] = st.top();
            }
            else if(s[i]==')'){
                v[i] = st.top();
                st.pop();
            }
            else if((s[i]=='+' || s[i]=='-') && st.size()>0){
                
                v[i] = st.top();
                st1.insert(st.top());   
            }
            else if((s[i]=='*' || s[i]=='/') && st.size()>0){
                
                v[i] = st.top();
                st3.insert(st.top());   
            }
            else if(st.size()>0){
                v[i] = st.top();
            }
            
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='*' && s[i]!='/' && s[i]!='-') continue;
            int j=i+1;
            if(s[i]=='-'){
                while(j<s.size()  && s[j]=='('){
                    if(st1.find(v[j])!=st1.end())
                    st2.insert(j);
                    j++;
                }
                continue;
            }
            j = i+1;
            while(j<s.size() && s[j]=='('){
                if(st1.find(v[j])!=st1.end())
                    st2.insert(j);
                    j++;
            }
            if(s[i]=='/'){
                j = i+1;
                while(j<s.size() && s[j]=='('){
                    if(st3.find(v[j])!=st3.end())
                        st2.insert(j);
                        j++;
                }
            }
           
            j = i-1;
            while(j>=0  && s[j]==')'){
                if(st1.find(v[j])!=st1.end())
                    st2.insert(j);
                    j--;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=')' && s[i]!='('){
                ans+=s[i];
            }
            else{
                if(st2.find(v[i])!=st2.end()){
                    ans+=s[i];
                }
            }
        }
        
        return ans;
    }
};