class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
    
    int n = a.size(); // Both arrays have size n
    int target = n; // We need the nth and (n+1)th elements
    
    int i = 0, j = 0, count = 0;
    int prev = 0, curr = 0;
    
    // Merge until we reach the (n+1)th element
    while (i < n && j < n && count <= target) {
        prev = curr;
        if (a[i] <= b[j]) {
            curr = a[i];
            i++;
        } else {
            curr = b[j];
            j++;
        }
        count++;
    }
    
    // Process remaining elements from a
    while (i < n && count <= target) {
        prev = curr;
        curr = a[i];
        i++;
        count++;
    }
    
    // Process remaining elements from b
    while (j < n && count <= target) {
        prev = curr;
        curr = b[j];
        j++;
        count++;
    }
    
    // Return average of nth and (n+1)th elements
    return (prev + curr) / 2.0;
    }
};