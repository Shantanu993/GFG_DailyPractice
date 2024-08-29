//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution{
	public:
	static bool cmp(vector<int>&a, vector<int>&b) {
	    return a[2]<b[2];
	}
	
	int find(int a,vector<int>&par) {
	    while(par[a]!=a) {
	        par[a]=par[par[a]];
	        a=par[a];
	    }
	    return a;
	}
	
	int doUnion(int a, int b,vector<int>&par,vector<int>&count) {
	    int x=find(a,par),y=find(b,par);
	    par[x]=par[y];
	    int paths=count[x]*count[y]; // No. of paths created by connecting a new edge
	    count[y]+=count[x]; // count[y] stores total nodes by connecting  x and y components
	    return paths;
	}

	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int>&queries) {
	    unordered_map<int,int> pathsLessThanK;
	    vector<int> ans,weights={-1},par, count(n+1,1);
        // Count[i] stores the number of connected nodes where i is the parent node
	    for(int i=0; i<=n;i++)par.push_back(i);
	    sort(edges.begin(),edges.end(),cmp);
	    for(auto i:edges) {
	        pathsLessThanK[i[2]]+=doUnion(i[0],i[1],par,count); // Stores total paths connected by edge weight i[2]
	        if(weights.back()!=i[2])weights.push_back(i[2]);
	    }
	    for(int i=1;i<weights.size();i++)pathsLessThanK[weights[i]]+=pathsLessThanK[weights[i-1]];
	    for(int a:queries) {
	        int ind=lower_bound(weights.begin(),weights.end(),a)-weights.begin();
	        if(ind==weights.size() or weights[ind]>a)ind--;
	        ans.push_back(pathsLessThanK[weights[ind]]);
	    }
	    return ans;
	}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends