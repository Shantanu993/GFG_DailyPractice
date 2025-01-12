//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        vector<int>preMax(n,0);
        vector<int>sufMax(n,0);
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,arr[i]);
            preMax[i]=maxi;
            
        }
        maxi = 0;
        for(int i=n-1;i>=0;i--)
        {
            maxi = max(maxi,arr[i]);
            sufMax[i]=maxi;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<preMax[i] && arr[i]<sufMax[i])
            {
                ans += min(preMax[i],sufMax[i])-arr[i];
            }
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends