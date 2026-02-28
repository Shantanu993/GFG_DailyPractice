class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        // Sorted array arr1 and arr2 
        int n = arr1.size();
        int m = arr2.size();
        
        int i = 0;
        int j = m - 1;
        
        vector<int> pair(2,0);
        
        int minDifference = INT_MAX;
        
        while(i<n && j>=0)
        {
            int pairSum = arr1[i] + arr2[j];
            int difference = pairSum - x;
            if(abs(difference)< minDifference)
            {
                minDifference = abs(difference);
                pair[0] = arr1[i];
                pair[1] = arr2[j];
            }
            if(difference > 0)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return pair;
    }
};