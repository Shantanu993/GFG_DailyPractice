//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        //Bayers Moore Majority Algo
        int count = 0;
        int candidate = -1;
        for(auto val : arr)
            {
                if(count ==0)
                    {
                        count = 1;
                        candidate = val;
                    }
                else if(candidate == val)
                    count++;
                else
                    count--;
            }
        count = 0;
        for(auto val : arr)
            {
                if(candidate == val)
                    count++;
            }
        return (count > arr.size()/2)?candidate:-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends