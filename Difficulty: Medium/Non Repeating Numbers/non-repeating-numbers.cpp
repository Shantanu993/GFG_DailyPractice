//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int diff=0;
        for(auto i:nums)
        {
            diff^=i;
        }
        diff&=-diff;
        vector<int> rec={0,0};
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&diff)==0)
            {
                rec[0]^=nums[i];
            }
            else
            {
                rec[1]^=nums[i];
            }
        }
        if(rec[0]>rec[1])
        {
            swap(rec[0],rec[1]);
        }
        return rec;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends