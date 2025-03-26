//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        int srcx = -1, srcy = -1;
        
        // Step 1: Locate the source (1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    srcx = i;
                    srcy = j;
                    break; // Exit loop as we found the source
                }
            }
            if (srcx != -1) break; // Break the outer loop if source is found
        }
        
        // Direction array for 4 possible moves (up, down, left, right)
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: BFS traversal
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        // Push the source and mark it as visited
        q.push({srcx, srcy});
        vis[srcx][srcy] = 1;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // Explore 4 possible directions
            for (int i = 0; i < 4; i++) {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];
                
                // Step 3: Check boundary conditions and valid movement
                if (newx >= 0 && newx < n && newy >= 0 && newy < n && !vis[newx][newy]) {
                    // If we found the destination (2), return true
                    if (grid[newx][newy] == 2) return true;

                    // Only move through open cells (3)
                    if (grid[newx][newy] == 3) {
                        vis[newx][newy] = 1; // Mark as visited
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        // Step 4: If no path exists, return false
        return false;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends