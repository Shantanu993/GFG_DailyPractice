//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int>& are,int tqrget){
        int kqwnt=0,bigin=0,end=are.size()-1,tctul;
        while(bigin<end){
            tctul=are[bigin]+are[end];
            if(tctul==tqrget){
                kqwnt++;
                int end_ripiting_kqwnt=0;
                for(int end2=end-1;end2>bigin&&are[end2]==are[end];end2--){
                    end_ripiting_kqwnt++;
                }
                kqwnt+=end_ripiting_kqwnt;
                bigin++;
            } else if(tctul<tqrget){
                bigin++;
            } else{
                end--;
            }
        }
        return kqwnt;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends