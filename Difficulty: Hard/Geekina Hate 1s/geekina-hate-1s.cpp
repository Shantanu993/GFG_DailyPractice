//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    long long nCr(int n, int r) {
        long long mn = min(r, n-r);
        long long mx = max(r, n-r);
        
        long long ans = 1;
        
        while (++mx <= n) {
            ans *= mx;
        }
        while (mn > 1) {
            ans /= mn--;
        }
        
        return ans;
    }
    
    long long findNthNumber(int n, int k) {
        // code here
        if (k == 1) return 1LL << (n-2);
        if (k >= 62) return n-1;
        if (n <= ((1LL << (k+1)) -1)) return n-1;
        
        /* stores total Ways of selecting 0 to 'r' set-bits from 'n' bits (n - row , r - column) */
        vector<vector<long long>> ncr;


        int bits = -1;  /* total bits using, to select from*/
        
        while (++bits < 64) {
            
            vector<long long> temp;
            temp.push_back(1);  /*way of selecting 0 bits from any number of bits is always 1 */


            int one = 0;    /*number of bits selecting (i.e. 'r') from current 'bits' */
            
            while (++one<=bits && one<=k) { /*selecting 0 to 'one' bits from 'bits' */
                temp.push_back(temp[one-1] + nCr(bits, one));
            }
            
            ncr.push_back(temp);
            
            /* if possible numbers are greater or equal than n'th number, then break */
            if (one > k && temp[k] > n) break;
        }
        /* answer lies in 'bits' number of bits
            because while selecting k set-bits from 'bits' bits are greater or equal,
            than the n'th number required
            and it also means that the 'bits' bit must be 1,
            because while selecting from 'bits-1' bits valid numbers were less
        */
        
        int nn = bits - 1;  /*look for remaining set bits needed */          int rr = k - 1;     /*1 set bit is found so k-1 can be selected now */
        long long ans = 1LL << nn;  /*store that found set bit in 'ans' */
        long long cnt = ncr[nn][k]; /*store count of valid numbers */
        
        /* till all bits are searched */
        while (nn >= 0) {
            rr = min(rr, nn);   /*because we can't select larger bits from lesser bits */
            
            /* if selecting from 'nn' bits, count is still more or equal, then decrease 'nn' */
            if (cnt + ncr[nn][rr] >= n) nn--;


            /* else if count is less than the required, then previous bit must be 1 */

            else {
                ans |= 1LL << nn;   /*so include it in answer*/
                cnt += ncr[nn][rr]; /*'count' till current bits, are less, so include that*/
                /* another bit is found so bits to be selected is decreased, but only if bits we are selecting from, are greater */
                if (nn > rr) rr--;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends