//Back-end complete function template in C++

class Solution {
  public:
    // Function to calculate the maximum height of stack of boxes.
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();

        int dp[10001]; // creating a dp array to store the maximum height
        vector<pair<pair<int, int>, int> > v; // creating a vector of pair to store all
                                              // possible combinations of dimensions
        memset(dp, 0, sizeof dp);             // initializing the dp array with 0 values
        v.clear();                            // clearing the vector

        // iterating through every box
        for (int i = 0; i < n; i++) {
            int a, b, c;
            a = height[i];
            b = width[i];
            c = length[i];

            // adding all possible combinations of dimensions to the vector
            v.push_back(make_pair(make_pair(a, b), c));
            v.push_back(make_pair(make_pair(b, a), c));
            v.push_back(make_pair(make_pair(a, c), b));
            v.push_back(make_pair(make_pair(c, a), b));
            v.push_back(make_pair(make_pair(b, c), a));
            v.push_back(make_pair(make_pair(c, b), a));

            sort(v.begin(), v.end()); // sorting the vector in lexicographically
                                      // increasing order of dimensions
        }

        sort(v.begin(), v.end()); // sorting the vector in lexicographically increasing
                                  // order of dimensions

        // iterating through all the combinations of dimensions in the vector
        for (int i = 0; i < v.size(); i++) {
            dp[i] = v[i].second; // setting the height of the current combination as the
                                 // height of the box

            // iterating through all the previous combinations of dimensions
            for (int j = 0; j < i; j++) {
                if (v[i].first.first > v[j].first.first and
                    v[i].first.second >
                        v[j].first
                            .second) { // checking if the current combination can be
                                       // stacked on top of the previous combination
                    dp[i] =
                        max(dp[i],
                            dp[j] + v[i].second); // updating the maximum height if the
                                                  // current combination can be stacked
                }
            }
        }

        int m = INT_MIN; // initializing the maximum height to minimum possible value
        for (int i = 0; i < v.size(); i++)
            m = max(dp[i], m); // finding the maximum height among all the combinations

        return m; // returning the maximum height
    }
};