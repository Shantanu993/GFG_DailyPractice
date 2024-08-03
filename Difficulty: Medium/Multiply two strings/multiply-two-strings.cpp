//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{

  public:   /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
      bool neg1 = false, neg2 = false;
    if (s1[0] == '-') {
        neg1 = true;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        neg2 = true;
        s2 = s2.substr(1);
    }

    int n = s1.size();
    int m = s2.size();

    // Result can be at most n + m digits
    vector<int> result(n + m, 0);

    // Perform the multiplication
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // Convert result vector to string
    string ans_str;
    bool leading_zero = true;
    for (int num : result) {
        if (leading_zero && num == 0) continue;
        leading_zero = false;
        ans_str += (num + '0');
    }

    // If the result is zero
    if (ans_str.empty()) return "0";

    // Add negative sign if needed
    if ((neg1 && !neg2) || (!neg1 && neg2)) {
        ans_str = '-' + ans_str;
    }

    return ans_str;
       
        
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends