//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> res;
    bool isSafe(int row, int col, vector<vector<int> > &board)
    {
        int n= board.size();
        int i, j;
        for(i=0;i<col;i++)
        {
            if(board[row][i] == 1) return false;
        }
        for(i=row, j=col;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]) return false;
        }
        for(i=row, j=col;i<n && j>=0;i++,j--)
        {
            if(board[i][j]) return false;
        }
        return true;
    }
    bool nq(vector<vector<int>> &board, int col)
    {
        int n = board.size();
        if(col == n)
        {
            vector<int> v;
            for(int i =0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j] == 1) v.push_back(j+1);
                }
            }
            res.push_back(v);
            return true;
        }
        
        bool ans = false;
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board))
            {
                board[i][col] = 1;
                ans = nq(board,col+1) || ans;
                board[i][col] = 0;
            }
        }
        return ans;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        res.clear();
        vector<vector<int>> board(n,vector<int>(n,0));
        if(nq(board, 0) == false) return {};
        
        sort(res.begin(),res.end());
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends