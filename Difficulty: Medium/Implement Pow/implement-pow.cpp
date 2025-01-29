//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
       bool sign=(b<0)?true:false;
       bool powerSign=(e<0)?true:false;
       e=abs(e);
       b=abs(b);
       int cnt=e;
       double ans=1.0;
       while(e>0){
            if(e&1){
                 ans=1.0*b*ans;
                 e--;
            }
            else{
                 b=b*b*1.0;
                 e/=2;
            }
       }
       if(powerSign){
            double val=1.0/ans;
            if(sign && cnt%2){
                 return -1.0*val;
            }
            else{
                 return val;
            }
       }
       if(sign && cnt%2){
            return -1.0*ans;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends