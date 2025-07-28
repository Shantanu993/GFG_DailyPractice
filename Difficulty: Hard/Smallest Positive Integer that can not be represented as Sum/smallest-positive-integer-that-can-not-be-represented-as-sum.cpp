class Solution {
public:
    long long smallestpositive(vector<long long> array, int n) {
        sort(array.begin(), array.end());

        long long result = 1;

        for (int i = 0; i < n && array[i] <= result; ++i) {
            result += array[i];
        }

        return result;
    }
};