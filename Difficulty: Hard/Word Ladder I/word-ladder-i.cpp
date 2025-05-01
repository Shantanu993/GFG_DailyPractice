//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        int n = wordList.size();
        map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[wordList[i]]++;
        }
        
        queue<pair<int,string>>q;
        q.push({1,startWord});
        while(!q.empty()){
            
            string str = q.front().second;
            int lvl = q.front().first;
            q.pop();
            
            if(str==targetWord)return lvl;
            
            for(int i=0;i<str.length();i++){
                char ch = str[i];
                for(char j='a';j<='z';j++){
                    if(j!=ch){
                        str[i]=j;
                        if(mp.find(str)!=mp.end()){
                            q.push({lvl+1,str});
                            mp.erase(str);
                        }
                    }
                }
                str[i]=ch;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends