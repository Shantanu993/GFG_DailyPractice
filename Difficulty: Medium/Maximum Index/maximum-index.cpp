//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{

public:
int maxIndexDiff(int arr[], int n)
{

    stack<pair<int, int>> s;
    int answer = 0;
    s.push({0, arr[0]});

    for (int i = 1; i < n; i++)
    {
        if (s.top().second > arr[i])
        {
            s.push({i, arr[i]});
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().second <= arr[i])
        {
            answer = max(answer, i - s.top().first);
            s.pop();
        }
    }
    return answer;
}


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends