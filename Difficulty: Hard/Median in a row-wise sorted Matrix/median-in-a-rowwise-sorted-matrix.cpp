//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{   
public:
int upperBound(vector<int> &vec, int n, int num){
    
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(vec[mid]>num){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    return ans;
    
}
int countofSmallValue(vector<vector<int>> &matrix, int r, int c, int num){
    int cnt=0;
    for(int i=0; i<r; i++){
        cnt+=upperBound(matrix[i], c, num);
        
        
    }
    return cnt;
}
    int median(vector<vector<int>> &matrix, int r, int c){
        int low=INT_MAX, high=INT_MIN;
        
        for(int i=0; i<r; i++){
            low=min(low, matrix[i][0]);
            high=max(high, matrix[i][c-1]);
        }
        
        
        int req=(r*c)/2;
        while(low<=high){
            int mid=(low+high)/2;
            
            int smallerValue=countofSmallValue(matrix, r, c, mid);
            if(smallerValue<=req){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends