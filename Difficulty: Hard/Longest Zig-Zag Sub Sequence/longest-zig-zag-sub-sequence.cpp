class Solution {
    public:
        int ZigZagMaxLength(vector<int>&nums){
            // If there are less than 2 elements in the array, return the size of the array
            if(nums.size() < 2)
                return nums.size();
            
            // Initialize the variables for tracking the length of zigzag sequence
            int up = 1, down = 1;
            
            // Iterate through the array starting from index 1
            for(int i = 1; i < nums.size(); i++){
                // If the current element is greater than the previous element, increase the length of the "up" sequence
                if(nums[i] > nums[i-1])
                    up = down + 1;
                // If the current element is less than the previous element, increase the length of the "down" sequence
                else if(nums[i] < nums[i-1])
                    down  = up + 1;
            }
            
            // Return the maximum length of the zigzag sequence
            return max(up, down);
        }
};