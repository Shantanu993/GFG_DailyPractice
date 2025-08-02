//Back-end complete function Template for C++

class Solution {
  public:
    // Function to find the maximum number of balls that can be collected.
    long long maxBalls(int n, int m, vector<int> a, vector<int> b) {
        long long asum = 0, bsum = 0;
        int i = 0, j = 0;
        // Iterating through the arrays a and b to compare elements.
        while (i < n && j < m) {
            // If the elements at current indices of a and b are equal.
            if (a[i] == b[j]) {
                long long sa = 0, sb = 0;
                int ia = i, jb = j;
                // Calculating the sum of consecutive equal elements in array a.
                while (i + 1 < n && a[i] == a[i + 1])
                    sa += a[i++];
                // Calculating the sum of consecutive equal elements in array b.
                while (j + 1 < m && b[j] == b[j + 1])
                    sb += b[j++];
                long long ea = i - ia + 1, eb = j - jb + 1;
                // Calculating the sum of elements considering different cases.
                long long e1 = asum + sa + a[i];
                if (ea > 1 && eb > 1)
                    e1 = max(e1, asum + ea * a[i] + eb * a[i] - 2 * a[i]);
                e1 = max(e1, bsum + ea * a[i] + eb * a[i] - a[i]);
                long long e2 = bsum + sb + a[i];
                if (ea > 1 && eb > 1)
                    e2 = max(e2, bsum + ea * a[i] + eb * a[i] - 2 * a[i]);
                e2 = max(e2, asum + ea * a[i] + eb * a[i] - a[i]);
                asum = e1;
                bsum = e2;
                i++, j++;
            }
            // If element in a is less than element in b.
            else if (a[i] < b[j]) {
                asum += a[i++];
            }
            // If element in b is less than element in a.
            else {
                bsum += b[j++];
            }
        }

        // Adding remaining elements in array a to asum.
        while (i < n)
            asum += a[i++];
        // Adding remaining elements in array b to bsum.
        while (j < m)
            bsum += b[j++];

        // Adding the maximum sum of elements from both arrays to the answer.
        return max(asum, bsum);
    }
};