/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
     void solve(Node* root,int& k,int& ans){
        if(root == nullptr)return;
        if(root->data <= k && root->data >= ans)ans = root->data;
        solve(root->left,k,ans);
        solve(root->right,k,ans);
    }
    int findMaxFork(Node* root, int k) {
        int ans= -1;
        solve(root,k,ans);
        return ans;
        
    }
};