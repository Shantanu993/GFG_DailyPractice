//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string b, string e, vector<string>& w) {
        int n=b.size();
        unordered_set<string>sets(w.begin(),w.end());
        if(sets.find(e)==sets.end())    return {};
        queue<vector<string>>que;
        que.push({b});
        vector<vector<string>>ans;
        vector<string>levels;
        int lvl=0;
        while(!que.empty()){
            vector<string>vec=que.front();
            que.pop();
            if(vec.size()>lvl){
                lvl++;
                
            for(auto i:levels)  sets.erase(i);
            }
            string temp=vec.back();
            if(temp==e){
                ans.push_back(vec);
            }
            for(int i=0;i<n;i++){
                char x=temp[i];
                for(int j=0;j<26;j++){
                    temp[i]=j+'a';
                    if(sets.find(temp)!=sets.end()){
                        vec.push_back(temp);
                        que.push(vec);
                        levels.push_back(temp);
                        vec.pop_back();
                    }
                }
                temp[i]=x;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends