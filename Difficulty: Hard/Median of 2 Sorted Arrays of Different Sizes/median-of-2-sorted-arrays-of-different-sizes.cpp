//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
         int n = array1.size();
        int m = array2.size();
        int totalSize = n + m;
        int medianPos1 = (totalSize - 1) / 2;
        int medianPos2 = totalSize / 2;
        
        int i = 0, j = 0;
        int current = 0;
        int median1 = 0, median2 = 0;
        
        while (i < n && j < m && current <= medianPos2) {
            int value;
            if (array1[i] < array2[j]) {
                value = array1[i++];
            } else {
                value = array2[j++];
            }

            if (current == medianPos1) {
                median1 = value;
            }
            if (current == medianPos2) {
                median2 = value;
            }
            current++;
        }

        while (i < n && current <= medianPos2) {
            if (current == medianPos1) {
                median1 = array1[i];
            }
            if (current == medianPos2) {
                median2 = array1[i];
            }
            i++;
            current++;
        }
        
        while (j < m && current <= medianPos2) {
            if (current == medianPos1) {
                median1 = array2[j];
            }
            if (current == medianPos2) {
                median2 = array2[j];
            }
            j++;
            current++;
        }
        
        if (totalSize % 2 == 0) {
            return (median1 + median2) / 2.0;
        } else {
            return median2;
        }
    }
    
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends