//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
        list<pair<int, int>> l;
        unordered_map<int, list<pair<int, int>>::iterator> m;
        int cap;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        l.clear();
        m.clear();
        this->cap = cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int x)
    {
        // your code here
        if(m.find(x) == m.end())
            return -1;
        int ans = m[x]->first;
        l.erase(m[x]);
        l.push_front(make_pair(ans, x));
        m[x] = l.begin();
        return ans;
    }
    
    //Function for storing key-value pair.
    void SET(int x, int y)
    {
        if(m.find(x) == m.end())
        {
            if(l.size() == cap)
            {
                pair<int, int> t = l.back();
                l.pop_back();
                m.erase(t.second);
            }
        }
        else
            l.erase(m[x]);
        //Your code here
        l.push_front(make_pair(y, x));
        m[x] = l.begin();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends