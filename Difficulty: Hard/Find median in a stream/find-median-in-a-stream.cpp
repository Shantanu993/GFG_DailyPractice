//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    // Declaring maxHeap as a max-priority queue
    priority_queue<int> maxHeap;
    
    // Declaring minHeap as a min-priority queue
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Function to insert elements into the appropriate heap.
    void insertHeap(int &x)
    {
        // If maxHeap is empty or the new element is less than or equal to the top of maxHeap,
        // insert into maxHeap.
        if(maxHeap.empty() || x <= maxHeap.top()) 
            maxHeap.push(x);
        else 
            minHeap.push(x);
        
        // Balance the heaps after insertion.
        balanceHeaps();
    }
    
    // Function to balance the heaps to ensure their sizes differ by at most one.
    void balanceHeaps()
    {
        // If minHeap has more than one extra element, move the top element to maxHeap.
        if(minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        // If maxHeap has more than one extra element, move the top element to minHeap.
        else if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    // Function to return the median of the elements inserted so far.
    double getMedian()
    {
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();
        
        // If both heaps have the same number of elements, the median is the average of the two tops.
        if(minHeapSize == maxHeapSize)
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        // If minHeap has more elements, the median is the top of minHeap.
        else if(minHeapSize > maxHeapSize)
        {
            return minHeap.top();
        }
        // If maxHeap has more elements, the median is the top of maxHeap.
        else
        {
            return maxHeap.top();
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends