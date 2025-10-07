class Solution {
  public:
    // function to get the hash key for remSq array
    long long getKey(vector<int> &remSq, int b) {
        long long base = 1;
        long long key = 0;
        for (int i = 0; i < b; i++) {
            key += ((long long)remSq[i] * (long long)base);
            base = base * (b + 1);
        }
        return key;
    }

    // Recursive function to find the minimum number of square cuts
    // for a given remSq array
    int minCutUtil(vector<int> &remSq, int a, int b, map<long long, int> &memo) {

        // pointers to mark the start and end of range
        // with maximum remaining squares
        int start, end;

        // Check if we have previously calculated the answer
        // for the same state
        long long key = getKey(remSq, b);
        if (memo.find(key) != memo.end())
            return memo[key];

        int maxRemSq = 0;

        // Find the starting point of min height
        for (int i = 0; i < b; i++) {
            if (remSq[i] > maxRemSq) {
                maxRemSq = remSq[i];
                start = i;
            }
        }

        // If max remaining squares = 0, then we have already
        // cut the entire paper
        if (maxRemSq == 0)
            return 0;

        end = start;
        vector<int> newRemSq = remSq;

        int ans = INT_MAX;

        // Find the ending point of min height
        while (end < b) {

            // length of edge of square from start till current end
            int squareEdge = end - start + 1;

            // If the current column does not have maximum remaining
            // squares or if it's impossible to cut a square of
            // size squareEdge, then break out of the loop
            if (newRemSq[end] != maxRemSq || newRemSq[end] - squareEdge < 0)
                break;

            // If we can cut a square of size squareEdge,
            // update the remainingSquares
            for (int i = start; i <= end; i++)
                newRemSq[i] = maxRemSq - squareEdge;

            // Find the solution for new remainingSquares
            ans = min(ans, 1 + minCutUtil(newRemSq, a, b, memo));
            end += 1;
        }

        return memo[key] = ans;
    }

    int minCut(int a, int b) {
        // if the given rectangle is a square
        if (a == b)
            return 1;

        // Initialize remaining squares = a for all the b columns
        vector<int> remSq(b, a);

        map<long long, int> memo;
        return minCutUtil(remSq, a, b, memo);
    }
};