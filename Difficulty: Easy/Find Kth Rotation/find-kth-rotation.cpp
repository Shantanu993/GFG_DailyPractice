class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        
        int n=arr.size();
        int val=arr[n-1];
        int idx=-1;
        
        if(n==1)
        {
            return 0;
        }
        
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<val)
            {
               val=arr[i];    
            }
            
            else
            {
                idx=i;
                break;
            }
        }
        
        return idx+1;
        
        
    }
};

