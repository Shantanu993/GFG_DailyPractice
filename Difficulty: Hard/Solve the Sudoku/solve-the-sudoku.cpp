//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a solved Sudoku. 
   bool isSafe(int grid[N][N], int row, int col, int num) {
        for (int x = 0; x < N; x++)
            if (grid[row][x] == num)
                return false;
        for (int x = 0; x < N; x++)
            if (grid[x][col] == num)
                return false;
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i + startRow][j + startCol] == num)
                    return false;
                    
        return true;
    }
    
    bool SolveSudoku(int grid[N][N]) { 
        int row, col;
        bool isUnassigned = false;
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (grid[row][col] == UNASSIGNED) {
                    isUnassigned = true;
                    break;
                }
            }
            if (isUnassigned)
                break;
        }
        if (!isUnassigned)
            return true;
        for (int num = 1; num <= 9; num++) {
            if (isSafe(grid, row, col, num)) {
                grid[row][col] = num;
                
                if (SolveSudoku(grid))
                    return true;
                
                grid[row][col] = UNASSIGNED;
            }
        }
        
        return false;
    }
    void printGrid(int grid[N][N]) { 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends