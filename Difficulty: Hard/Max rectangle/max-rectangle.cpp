//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    vector<int> getnextlesserleft(vector<int> &arr, int n){
       vector<int> nextlesserleft(n);
       stack<pair<int,int>> st;
       int i=0;
       while(i<n){
           if(st.empty()){
               nextlesserleft[i]=-1;
           }
           else if(!st.empty() && st.top().first<arr[i]){
                nextlesserleft[i]=st.top().second;
           }
           else if(!st.empty() && st.top().first>=arr[i]){
               while(!st.empty() && st.top().first>=arr[i]){
                   st.pop();
               }
               if(st.empty()){
                   nextlesserleft[i]=-1;
               }
               else{
                    nextlesserleft[i]=st.top().second;
               }
           }
           st.push({arr[i],i});
           i++;
       }
       return nextlesserleft;
       
    }
    
    vector<int> getnextlesserright(vector<int> &arr, int n){
        vector<int> nextlesserright(n);
        stack<pair<int,int>> st;
        int i=n-1;
        while(i>=0){
           if(st.empty()){
              nextlesserright[i]=n;
           }
           else if(!st.empty() && st.top().first<arr[i]){
                nextlesserright[i]=st.top().second;
           }
           else if(!st.empty() && st.top().first>=arr[i]){
               while(!st.empty() && st.top().first>=arr[i]){
                   st.pop();
               }
               if(st.empty()){
                   nextlesserright[i]=n;
               }
               else{
                    nextlesserright[i]=st.top().second;
               }
           }
           st.push({arr[i],i});
           i--;
       }
       return nextlesserright;
        
    }
    
    int getMaxArea(vector<int> &arr, int n)
    {
        // Your code here
        // find next lowest index on Left and Right
        vector<int> nextlesserleft(n);
        vector<int> nextlesserright(n);
        nextlesserleft=getnextlesserleft(arr, n);
        nextlesserright=getnextlesserright(arr, n);
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int area = (nextlesserright[i]-nextlesserleft[i]-1)*arr[i];
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxi = 0;
        vector<int> addedarray(m);
        for(int j=0;j<m;j++){
            addedarray[j]=M[0][j];
        }
        maxi = max(maxi,getMaxArea(addedarray,m));
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    addedarray[j]=0;
                }
                else{
                    addedarray[j]+=1;
                }
            }
            maxi = max(maxi,getMaxArea(addedarray,m));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends