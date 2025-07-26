class Solution {
public:
    vector<vector<int>> solve(int n, int p, vector<int>& a, vector<int>& b, vector<int>& d) {
        // Initialize arrays
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        vector<int> to(n + 1, 0);
        vector<int> diameter(n + 1, 0);
        
        // Build the graph representation
        for (int i = 0; i < p; ++i) {
            int u = a[i];
            int v = b[i];
            int dia = d[i];
            outdegree[u] = 1;
            indegree[v] = 1;
            to[u] = v;
            diameter[u] = dia;
        }
        
        vector<vector<int>> result;
        
        // Traverse from each tank (start node)
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0 && outdegree[i] == 1) {
                int current = i;
                int min_dia = INT_MAX;
                while (outdegree[current] == 1) {
                    min_dia = min(min_dia, diameter[current]);
                    current = to[current];
                }
                // current now points to the tap node
                result.push_back({i, current, min_dia});
            }
        }
        
        // Sort by tank house number
        sort(result.begin(), result.end());
        
        return result;
    }
};