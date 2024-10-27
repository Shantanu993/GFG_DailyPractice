//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


class Solution
{
private:

public:
    map<Node*, Node*>par;
    Node* tar = NULL;
    void dfs(Node* root, Node* p, int t) {
        if(!root) return;
        if(root->data == t) tar = root;
        par[root] = p;
        dfs(root->left, root, t);
        dfs(root->right, root, t);
    }
    map<int, int>vis;
    vector <int> KDistanceNodes(Node* root, int t , int k)
    {
        // return the sorted vector of all nodes at k dist
        dfs(root, NULL, t);
        vector<int>res;
        queue<Node*>q;
        q.push(tar);
        vis[tar->data]++;
        while(k--) {
            int sz = q.size();
            // cout<<sz<<" ";
            while(sz--){
                Node* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left->data]) {q.push(curr->left); vis[curr->left->data]++;}
                if(curr->right && !vis[curr->right->data]) {q.push(curr->right); vis[curr->right->data]++;}
                if(par[curr] && !vis[par[curr]->data]) {q.push(par[curr]); vis[par[curr]->data]++;}
                
            }
        }
        while(q.size()){
            res.push_back(q.front()->data);
            q.pop();
        }
        sort(res.begin(), res.end());
        par.clear();
        vis.clear();
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends