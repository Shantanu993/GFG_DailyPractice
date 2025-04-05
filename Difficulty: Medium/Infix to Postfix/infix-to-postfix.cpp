//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int prio(char ch){
        if(ch=='^') return 3;
        else if(ch=='*'||ch=='/') return 2;
        // else if(ch=='+'||ch=='-') 
        return 1;
        // return 0;
    }
    string infixToPostfix(string& s) {
        int n=s.size();
        stack<string>val;
        stack<char>op;
        
        for(int i=0;i<n;i++){
            if(isalnum(s[i])) val.push(string(1, s[i])); 
            
            else if(!op.size()||s[i]=='(') op.push(s[i]);
            
            else if(s[i]==')'){
                
                while(op.top()!='('){
                    string x=val.top();
                    val.pop();
                    string y=val.top();
                    val.pop();
                    string temp=y+x+op.top();
                    op.pop();
                    val.push(temp);
                    
                }
                op.pop();
                
            }
            else{
                while(op.size()&&op.top() != '('&&prio(op.top())>=prio(s[i])){
                    
                    string x=val.top();
                    val.pop();
                    string y=val.top();
                    val.pop();
                    string temp=y+x+op.top();
                    op.pop();
                    val.push(temp);
                    
                    
                }
                op.push(s[i]);
            }
                
            
        }
        while (!op.empty()) {
            string b = val.top(); val.pop();
            string a = val.top(); val.pop();
            char oper = op.top(); op.pop();
            val.push(a + b + oper);
        }
        return val.top();
        
        
    }
};




//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends