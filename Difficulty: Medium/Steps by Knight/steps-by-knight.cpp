//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
           if(KnightPos==TargetPos){
               return 0;
           }
           queue<pair<int,int>>q;
           q.push({KnightPos[0]-1,KnightPos[1]-1});
           vector<vector<int>>dist(N,vector<int>(N,0));
           while(!q.empty()){
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
               int dis=dist[x][y];
               for(int k=0;k<8;k++){
                   int newx=x+dx[k];
                   int newy=y+dy[k];
                   if(newx>=0 && newx<N && newy>=0 && newy<N && !dist[newx][newy]){
                       if(newx==TargetPos[0]-1 && newy==TargetPos[1]-1){
                           return 1+dis;
                       }
                       q.push({newx,newy});
                       dist[newx][newy]=1+dis;
                   }
               }
           }
           return -1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends