//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        if (n == 0) return 0;

        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Initialize starting point
        cost[0][0] = grid[0][0];
        minHeap.push({grid[0][0], {0, 0}});

        // Directions for moving in the grid (down, up, right, left)
        vector<int> dirX = {1, -1, 0, 0};
        vector<int> dirY = {0, 0, 1, -1};

        while (!minHeap.empty()) 
        {
            auto topElement = minHeap.top();
            minHeap.pop();
            int currentCost = topElement.first;
            int x = topElement.second.first;
            int y = topElement.second.second;

            // If we've reached the bottom-right corner, return the cost
            if (x == n - 1 && y == n - 1) 
                return currentCost;

            // Explore the 4 possible directions
            for (int i = 0; i < 4; ++i) 
            {
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                
                // Check if the new cell is within bounds
                if (newX >= 0 && newX < n && newY >= 0 && newY < n) 
                {
                    int newCost = currentCost + grid[newX][newY];
                    
                    // Only update if a cheaper path is found
                    if (newCost < cost[newX][newY]) 
                    {
                        cost[newX][newY] = newCost;
                        minHeap.push({newCost, {newX, newY}});
                    }
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
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends