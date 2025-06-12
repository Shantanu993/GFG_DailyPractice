class Solution {
private:
    vector<int> getClosestElements(int left,int right, int n, int k,
                                    int x, vector<int> &arr)
    {
        vector<int> ans;
        
        while(k--) {
            int leftElement=INT_MAX, rightElement=INT_MAX;
            if(left>=0) leftElement=arr[left];
            if(right<n) rightElement=arr[right];
            
            if(rightElement==INT_MAX && leftElement==INT_MAX)
                continue;
            
            int leftAbs=abs(leftElement-x);
            int rightAbs=abs(rightElement-x);
            
            if(leftAbs<rightAbs) {
                ans.push_back(leftElement);
                left--;
            } else {
                ans.push_back(rightElement);
                right++;
            }
        }
        
        return ans;
    }
    
public:
    vector<int> printKClosest(vector<int> arr, int k, int x) 
    {
        int idx=-1, n=arr.size(), i=0, j=n-1;
        
        while(i<=j) {
            int mid=i+(j-i)/2;
            
            if(arr[mid]==x) {
                idx=mid;
                break;
            } else if(arr[mid]<x)   i=mid+1;
            else    j=mid-1;
        }
        
        vector<int> ans;
        if(idx==-1) ans=getClosestElements(j,i,n,k,x,arr);
        else    ans=getClosestElements(idx-1,idx+1,n,k,x,arr);
        
        return ans;
    }
};