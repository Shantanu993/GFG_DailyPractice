#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxPoints(int X[], int Y[], int N) {
        if (N <= 2)
            return N;

        int result = 2;

        for (int i = 0; i < N; i++) {
            std::unordered_map<double, int> slopeFrequency;
            int verticalPoints = 0, currentMax = 1, overlappingPoints = 0;

            for (int j = 0; j < N; j++) {
                if (i != j) {
                    if (X[i] == X[j]) {
                        if (Y[i] == Y[j]) {
                            overlappingPoints++;
                        } else {
                            verticalPoints++;
                            currentMax = std::max(currentMax, verticalPoints + 1);
                        }
                    } else {
                        double slope = (double)(Y[j] - Y[i]) / (double)(X[j] - X[i]);
                        slopeFrequency[slope]++;
                        currentMax = std::max(currentMax, slopeFrequency[slope] + 1);
                    }
                }
            }

            result = std::max(result, std::max(currentMax + overlappingPoints, verticalPoints + overlappingPoints));
        }

        return result;
    }
};

