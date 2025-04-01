//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int X[100], ok;

    void Sinh(int n){
	    int i = n-1;
	    while((i >= 0) and (X[i] == 1)){
		    X[i] = 0;
		    --i;
	    }
	    if(i == -1) ok = false;
	    else{
		    X[i] = 1;
	    }
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(begin(arr), end(arr));
        for(int i = 0; i < n; i++){
        	X[i] = 0;
		}
		ok = true;
		map<vector<int>, int> mp;
		while(ok){
			vector<int> tmp;
			for(int i = 0; i < n; i++){
				if(X[i] == 1){
					tmp.push_back(arr[i]);
				}
			}
			mp[tmp] = 1;
			Sinh(n);
		}
		vector<vector<int>> res;
		for(auto x : mp){
			res.push_back(x.first);
		}
		return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    
cout << "~" << "\n";
}
}   



// } Driver Code Ends