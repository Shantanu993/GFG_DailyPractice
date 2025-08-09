class Solution {
  public:
    int numOfSubsets(vector<int>& arr, int k) {
        int n = arr.size();
        // declare four vector for dividing array into
        // two halves and storing product value of
        // possible subsets for them
        vector<int> vect1, vect2, subset1, subset2;

        // ignore element greater than k and divide
        // array into 2 halves
        for (int i = 0; i < n; i++) {

            // ignore element if greater than k
            if (arr[i] > k)
                continue;
            if (i <= n / 2)
                vect1.push_back(arr[i]);
            else
                vect2.push_back(arr[i]);
        }

        // generate all subsets for 1st half (vect1)
        for (int i = 0; i < (1 << vect1.size()); i++) {
            int value = 1;
            for (int j = 0; j < vect1.size(); j++) {
                if (i & (1 << j))
                    value *= vect1[j];
                if (value > k)
                    break;
            }

            // push only in case subset product is less
            // than equal to k
            if (value <= k)
                subset1.push_back(value);
        }

        // generate all subsets for 2nd half (vect2)
        for (int i = 0; i < (1 << vect2.size()); i++) {
            int value = 1;
            for (int j = 0; j < vect2.size(); j++) {
                if (i & (1 << j))
                    value *= vect2[j];
                if (value > k)
                    break;
            }

            // push only in case subset product is
            // less than equal to k
            if (value <= k)
                subset2.push_back(value);
        }

        // sort subset2
        sort(subset2.begin(), subset2.end());

        int count = 0;
        for (int i = 0; i < subset1.size(); i++)
            count += upper_bound(subset2.begin(), subset2.end(), (k / subset1[i])) -
                     subset2.begin();

        // for null subset decrement the value of count
        count--;

        // return count
        return count;
    }
};