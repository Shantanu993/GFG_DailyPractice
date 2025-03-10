//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int>adj[N];
         vector<int>Indeg(N,0);
        for(int i=0;i<P;i++)
        {
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
            // Indeg[prerequisites[i].first]++;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                Indeg[adj[i][j]]++;
            }
        }
 
    queue<int>q;
    vector<int>ans;
    
    for(int i=0;i<Indeg.size();i++)
    {
        if(Indeg[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            Indeg[adj[node][i]]--;
            if(Indeg[adj[node][i]]==0)
            {
                q.push(adj[node][i]);
            }
        }
    }
    return ans.size()==N;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends