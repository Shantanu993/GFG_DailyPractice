class Solution {
  public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        // Use 0.0 to ensure floating-point accumulation
        double tot = accumulate(arr.begin(), arr.end(), 0.0);
        double target = tot / 2.0;
        
        priority_queue<double> pq;
        for (auto &it : arr) {
            pq.push((double)it);
        }

        int count = 0;
        // Use '>' instead of '>=' to avoid one extra iteration
        while (tot > target) {
            double top = pq.top();
            pq.pop();
            tot -= top / 2.0;       // reduce total sum
            pq.push(top / 2.0);     // push halved value back
            count++;
        }
        return count;
    }
};