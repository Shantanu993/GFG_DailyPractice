class Solution {
  public:
    // Helper to check if we can maintain max distance ≤ dist using ≤ k extra stations
    bool canPlace(const vector<double>& stations, int k, double dist) {
        int count = 0;
        for (int i = 0; i < stations.size() - 1; ++i) {
            double gap = stations[i + 1] - stations[i];
            count += int(gap / dist);  // Floor division
        }
        return count <= k;
    }

    // Main function to find smallest max distance after placing k extra stations
    double findSmallestMaxDist(vector<int> &stations, int k) {
        vector<double> pos(stations.begin(), stations.end());

        double low = 0.0, high = pos.back() - pos.front();
        double eps = 1e-6;

        while (high - low > eps) {
            double mid = (low + high) / 2.0;
            if (canPlace(pos, k, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;  // Let setprecision handle 2-decimal formatting in main()
    }
};