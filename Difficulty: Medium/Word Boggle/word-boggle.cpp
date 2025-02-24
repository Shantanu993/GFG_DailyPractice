//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    set<string>st;
    bool solve(vector<vector<char>>b,vector<vector<int>>&vis,string s,int i,int j,int ind){
        if(ind==s.size()) return true;
        vis[i][j]=1;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                int x=dx+i,y=dy+j;
                if(x>=0 && y>=0 && x<b.size() && y<b[0].size() && vis[x][y]==0
                && b[x][y]==s[ind]){
                    if(solve(b,vis,s,x,y,ind+1)) return true;
                }
            }
        }
        vis[i][j]=0;
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    int n=dictionary.size();
	    vector<string>ans;
	    
	    for(string word:dictionary){
	        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
	        for(int i=0;i<board.size();i++){
	            for(int j=0;j<board[0].size();j++){
	                if(word[0]==board[i][j]){
	                    if(solve(board,vis,word,i,j,1)){
	                        if(find(ans.begin(),ans.end(),word)==ans.end()){
	                            ans.push_back(word);
	                        }
	                    }
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends