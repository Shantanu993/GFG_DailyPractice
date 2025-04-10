//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& a) {
        int n=a.size();
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                int d=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(n,0),dist(n,INT_MAX);
        int ans=0;
        while(!pq.empty())
        {
            pair<int,int> front=pq.top();
            pq.pop();
            int cost=front.first;
            int node=front.second;
           
            if(vis[node]) continue;
            vis[node]=1;
            ans+=cost;
            
            for(auto &it:adj[node])
            {
                if(!vis[it.first] && it.second<dist[it.first])
                {
                    dist[it.first]=it.second;
                    pq.push({it.second,it.first});
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
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends