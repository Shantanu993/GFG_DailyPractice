class Solution {
  public:
    // Function to perform depth-first search to find the longest increasing path.
    int DFS(vector<vector<int>>& matrix, int y, int x, int val,
            vector<vector<int>>& hash) {
        // Checking if we are out of bounds.
        if (y < 0 || y >= matrix.size() || x < 0 || x >= matrix[0].size())
            return 0;

        // Checking if the current cell's value is greater than the previous cell's
        // value.
        if (matrix[y][x] > val) {
            // Checking if this path has already been searched.
            if (hash[y][x] != 0)
                return hash[y][x];

            // Performing DFS on all adjacent cells and finding the maximum length.
            int a = DFS(matrix, y, x + 1, matrix[y][x], hash) + 1;
            int b = DFS(matrix, y, x - 1, matrix[y][x], hash) + 1;
            int c = DFS(matrix, y + 1, x, matrix[y][x], hash) + 1;
            int d = DFS(matrix, y - 1, x, matrix[y][x], hash) + 1;

            // Storing the maximum length in the hash array for memoization.
            hash[y][x] = max(a, max(b, max(c, d)));
            return hash[y][x];
        }

        // If the current cell's value is not greater than the previous cell's value,
        // return 0.
        return 0;
    }

    // Function to find the longest increasing path in the matrix.
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Checking if the matrix is empty.
        if (matrix.size() == 0)
            return 0;

        int Max = 0;
        vector<int> tem(matrix[0].size(), 0);

        // Creating a hash array to store the lengths of already searched paths.
        vector<vector<int>> hash(matrix.size(), tem);

        // Performing DFS on each cell in the matrix and finding the maximum length.
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);

        // Returning the maximum length found.
        return Max;
    }
};