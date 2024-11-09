//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    string minSum(vector<int> &arr) {
        int size=arr.size();
        vector<int>v1,v2;
        sort(arr.begin(),arr.end());
        for(int i=0;i<size;i+=2)
        {
            v1.push_back(arr[i]);
            if(i+1<size)
            {
                v2.push_back(arr[i+1]);
            }
        }
         
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        string ans="";
        int i;
        int carry=0;
        
        for( i=0;i<v1.size()&&i<v2.size();i++)
        {
            int sum=v1[i]+v2[i]+carry;
            int rem=sum%10;
            carry=sum/10;
            ans+=to_string(rem);
        }
        if(i<v1.size())
        {
            ans+=to_string(v1[i]+carry);
            carry=0;
        }
        if(i<v2.size())
        {
            ans+=to_string(v2[i]+carry);
            carry=0;
        }
        if(carry!=0){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        int x=0;
        i=0;
        if(ans[0]=='0')
        {
           while(ans[i]=='0')
           {
               x++;
               i++;
           }
        }
        return ans.substr(x);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends