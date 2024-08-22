//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k)
    {
        set<int>adj[k];
        for(int i=1;i<n;i++)
        {
            string s1=dict[i-1];
            string s2=dict[i];
            
            int n1=s1.size();
            // for(int j=i+1;j<n;j++)
            // {
                int l=0,r=0;
                int n2=s2.size();
                while(l<n1 and r<n2)
                {
                    if(s1[l]==s2[r]){l++;r++;}
                    else
                    {
                        // cout<<s1[l]<<" "<<s2[r]<<endl;
                        adj[s1[l]-'a'].insert(s2[r]-'a');
                        break;
                    }
                }
            // }
        }
        vector<int>deg(k,0);
        for(int i=0;i<k;i++)
        {
            for(auto it:adj[i])
            {
                deg[it]++;
            }
        }
        string ans="";
        queue<int>q;
        for(int i=0;i<k;i++){
            if(deg[i]==0)
            {
                // cout<<i<<endl;
                ans+=char(i+'a');
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            for(auto itt:adj[it])
            {
                if(deg[itt]==0){continue;}
                deg[itt]--;
                if(deg[itt]==0){
                    // cout<<itt<<endl;
                    ans+=char(itt+'a');
                    q.push(itt);
                }
            }
        }
        // cout<<ans<<endl;
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends