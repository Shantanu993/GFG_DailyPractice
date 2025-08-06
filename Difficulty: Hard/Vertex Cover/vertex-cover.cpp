//Back-end complete function Template for C++

class Solution{
    public:
    bool checkCover(int n, int k, int m, vector<vector<int>> &e) {
    	// Set has first 'k' bits high initially
    	int set = (1 << k) - 1;
    
    	int limit = (1 << n);
    
    	// To mark the edges covered in each subset of size 'k'.
    	bool visited[n + 1][n + 1];
    
    	while (set < limit) {
    		// Reset visited array for every subset of vertices.
    		memset(visited, 0, sizeof(visited));
    
    		// Set counter for number of edges covered from this subset of vertices to zero.
    		int cnt = 0;
    
    		// Selected vertex cover is the indices where 'set' has its bit high.
    		for (int j = 1, v = 1; j < limit; j = j << 1, v++) {
    			if (set & j) {
    				// Mark all edges emerging out of this vertex visited
    				for (int k = 1; k <= n; k++) {
    					if (e[v][k] && !visited[v][k]) {
    						visited[v][k] = 1;
    						visited[k][v] = 1;
    						cnt++;
    					}
    				}
    			}
    		}
    
    		// If the current subset covers all the edges
    		if (cnt == m) {
    			return true;
    		}
    
    		// Generate previous combination with k bits high set & -set = (1 << last bit high in set).
    		int c = set & -set;
    		int r = set + c;
    		set = (((r ^ set) >> 2) / c) | r;
    	}
    	return false;
    }

    int vertexCoverHelper(vector<vector<int>> e, int n, int m) {
    	// Binary search the answer.
    	int low = 1, high = n;
    
    	while (high > low) {
    		int mid = (low + high) >> 1;
    
    		if (checkCover(n, mid, m, e) == false) {
    			low = mid + 1;
    		}
    		else {
    			high = mid;
    		}
    	}
    	return low;
    }

int vertexCover(int n, vector<pair<int, int>> &edges) {

	int m = edges.size();

	vector<vector<int>> e(n + 1, vector<int>(n + 1, 0));

	// Push the adjacent nodes for each node.
	for (int i = 0; i < m; i++) {
		e[edges[i].first][edges[i].second] = 1;
		e[edges[i].second][edges[i].first] = 1;
	}
	return vertexCoverHelper(e, n, m);
    }
};