//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<int>flag(arr.size(),0);
        vector<vector<string>>ret;
        for( int i=0;i<arr.size();i++){
            if( flag[i]==0){
                vector<string>reti;
                reti.push_back(arr[i]);
                string temp=arr[i];
                sort(temp.begin(),temp.end());
                
            for( int j=i+1;j<arr.size();j++){
                if( flag[j]==0){
                    string tempi=arr[j];
                    sort(tempi.begin(),tempi.end());
                    if( tempi==temp){
                        reti.push_back(arr[j]);
                        flag[j]=1;
                    }
                    
                    
                }
                
            }
                 ret.push_back(reti);
            }
           
        }
        
        
        return ret;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends