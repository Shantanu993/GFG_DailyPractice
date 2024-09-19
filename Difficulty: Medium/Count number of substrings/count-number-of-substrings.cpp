//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
  public:
  
       
    // Helper function to count substrings with at most k distinct characters
    long long int solve(string s, int k) {
        if (k == 0) return 0;  // Edge case handling
    
        long long int count = 0;
        int left = 0, right = 0, n = s.size();
        vector<int> freq(26, 0);  // Frequency array for each character (assuming lowercase English letters)
        int distinctCount = 0;    // To track the number of distinct characters in the window
    
        for (; right < n; right++) {
            // Add the character at right pointer
            if (freq[s[right] - 'a']++ == 0) {
                distinctCount++;  // If the character appears for the first time, increase distinct count
            }
    
            // Shrink the window from the left if we have more than k distinct characters
            while (distinctCount > k) {
                if (--freq[s[left] - 'a'] == 0) {
                    distinctCount--;  // If the character count drops to zero, decrease distinct count
                }
                left++;  // Move the left pointer to shrink the window
            }
    
            // Add the number of valid substrings in the current window
            count += (right - left + 1);
        }
    
        return count;
    }
  
    long long int substrCount (string s, int k) {
    	//code here.
    	// Substrings with exactly k distinct characters =
        // Substrings with at most k distinct characters - Substrings with at most (k-1) distinct characters
        return solve(s, k) - solve(s, k - 1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends