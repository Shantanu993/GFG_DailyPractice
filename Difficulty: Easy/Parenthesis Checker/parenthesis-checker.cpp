//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
      stack<char> st;
       for(auto &e : x){
           if(e == '(' || e == '[' || e == '{'){
               st.push(e);
           }
           else{
               if(st.empty()){
                   return false;
               }
               else{
                   auto curr = st.top();
                   if(e == ')' && curr != '('){
                       return false;
                   }
                   else if(e == '}' && curr != '{'){
                       return false;
                   }
                   else if(e == ']' && curr != '['){
                       return false;
                   }
                   else{
                       st.pop();
                   }
               }
           }
       }
       if(st.empty()){
           return true;
       }
       return false;   // Your code here
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends