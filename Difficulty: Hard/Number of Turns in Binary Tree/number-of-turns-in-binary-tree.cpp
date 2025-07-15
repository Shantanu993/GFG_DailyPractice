class Solution {
  private:
    int turns = 0;
    int p, q;
    Node* dfs1(Node* node) {
        if (node == nullptr) return nullptr;
        if (node -> data == p || node -> data == q) return node;
        Node* left = dfs1(node -> left);
        Node* right = dfs1(node -> right);
        if (left != nullptr && right != nullptr) return node;
        return left ? left : right;
    }
    void dfs2(Node* node, bool leftPath, bool rightPath, int count) {
        if (node == nullptr) return;
        if (node -> data == p || node -> data == q) 
            turns += count;
        dfs2(node -> left, true, false, leftPath ? count : count + 1);
        dfs2(node -> right, false, true, rightPath ? count : count + 1);
    }
  public:
    int NumberOFTurns(struct Node* root, int first, int second) {
        p = first; q = second;
        Node* LCA = dfs1(root);
        dfs2(LCA, true, true, 0);
        if (LCA -> data == first || LCA -> data == second) 
            return turns;
        return turns + 1;
    }
};