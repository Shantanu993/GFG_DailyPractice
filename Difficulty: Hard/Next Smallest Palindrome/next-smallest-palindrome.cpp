//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution{
public:

    bool isallnine(int *num, int n){
        for(int i=0; i<n; i++){
            if(num[i]!=9) return false;}
            
            return true;
        
    }
    
    void Nextpalindromeunntil(int num[], int n){
        int mid = n/2;
        
        bool leftSmaller = false;
        
        int i = mid -1;
        int j = (n % 2 == 0) ? mid : mid + 1;
        
        while(i>=0 && num[i]==num[j])
        {
            i--;
            j++;
        }
        
        if(i<0 || num[i]<num[j])
        leftSmaller = true;
        
        while(i >= 0){
            num[j] = num[i];
            j++;
            i--;
        }
        
        if(leftSmaller == true){
            int carry = 1;
            
            i = mid-1;
            if(n%2==1){
                num[mid] += carry;
                carry = num[mid]/10;
                num[mid]%=10;
                j = mid +1;
            }
            
            else{
                j = mid;
            }
            
            while (i >= 0 && carry > 0) {  // ✅ Correct condition
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;
                num[j++] = num[i--];  // ✅ Correct position for j++
            }
        }
        
    }
    
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    vector<int>ans;
	   if (isallnine(num, n)) {
            ans.push_back(1);
            for (int i = 0; i < n - 1; i++) { // ✅ Fix: n-1 instead of n
                ans.push_back(0);
            }
            ans.push_back(1);
        return ans;  // ✅ Immediately return to avoid further processing
        }

	    
	    else{
	        Nextpalindromeunntil(num,n);
	        
	        for(int i=0; i<n; i++){
	            ans.push_back(num[i]);
	        }
	    }
	    
	    return ans;
	    
	}

};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends