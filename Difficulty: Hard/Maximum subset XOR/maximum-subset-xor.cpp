// Function to return maximum XOR subset in set[]

class Solution {
  public:
    int maxSubsetXOR(int arr[], int N)
    {
        if(N==0)    return 0;
        int x=0;
        // run a infinite loop 
        while(1){
            // find max element from array
            int y = *max_element(arr,arr+N);
            // if max element is 0, all elements in arr
            // have been reduced to 0
            // so return the maximum XOR found..
            if(y==0)    return x;
            
            // Update x to be max of x and x^y(may be larger than x)
            x = max(x, x^y);
            // Update each element to be min(element, element^ y(largest))
            //Remove the bit y from all elements that have it 
            for(int i=0;i<N;i++){
                arr[i] = min(arr[i], arr[i]^y);
            }
        }
        // this will never reached since ans will return inside infinite loop.
        return x;
    }
};