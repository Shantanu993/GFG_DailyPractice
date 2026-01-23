class Solution {
  public:
    int maxPeople(vector<int> &heights) {
        int size = heights.size();
        vector<int> nearestLeft(size, -1), nearestRight(size, size);
        stack<int> indexStack;

        // Find nearest taller or equal person on the LEFT
        for (int current = 0; current < size; current++) {
            while (!indexStack.empty() &&
                   heights[indexStack.top()] < heights[current]) {
                indexStack.pop();
            }
            if (!indexStack.empty())
                nearestLeft[current] = indexStack.top();

            indexStack.push(current);
        }

        // Clear stack
        while (!indexStack.empty()) indexStack.pop();

        // Find nearest taller or equal person on the RIGHT
        for (int current = size - 1; current >= 0; current--) {
            while (!indexStack.empty() &&
                   heights[indexStack.top()] < heights[current]) {
                indexStack.pop();
            }
            if (!indexStack.empty())
                nearestRight[current] = indexStack.top();

            indexStack.push(current);
        }

        int maxVisiblePeople = 0;

        for (int i = 0; i < size; i++) {
            int visibleOnLeft  = i - nearestLeft[i] - 1;
            int visibleOnRight = nearestRight[i] - i - 1;

            maxVisiblePeople = max(
                maxVisiblePeople,
                visibleOnLeft + visibleOnRight + 1  // +1 for self
            );
        }

        return maxVisiblePeople;
    }
};