//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int k) {
        int start=0;
        int end=0;
        int result=0;
        for(int i=0;i<N;i++){
            start=max(start,arr[i]);
            end+=arr[i];
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            int subArrayCount=1;
            int currSum=0;
            for(int i=0;i<N;i++){
                currSum+=arr[i];
                if(currSum>mid){
                    subArrayCount++;
                    currSum=arr[i];
                }
            }
            if(subArrayCount>k){
                start=mid+1;
            }
            else{
                result=mid;
                end=mid-1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends