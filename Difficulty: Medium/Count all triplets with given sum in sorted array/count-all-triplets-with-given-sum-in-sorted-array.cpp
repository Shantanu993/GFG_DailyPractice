//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int st=i+1,end=n-1;
            while(st<end){
                if(arr[st]+arr[end]==target-arr[i]){
                    // cnt++;
                    int t1=1,t2=1;
                    while(st+t1<end && arr[st+t1]==arr[st]){
                        t1++;
                    }
                    // while(end-1>st && arr[end-1]==arr[end]){
                    //     end--;t2++;
                    // }
                    end--;
                    cnt+=t1;
                }
                else if(arr[st]+arr[end]>target-arr[i])end--;
                else st++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends