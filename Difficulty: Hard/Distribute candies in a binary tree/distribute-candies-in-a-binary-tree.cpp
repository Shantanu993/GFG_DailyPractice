class Solution {
  public:
    // Utility function to find the number of
    // moves to distribute all of the candies
    int distributeCandyUtil(Node* root, int& ans) {

        // Base Case
        if (root == nullptr)
            return 0;

        // Traverse left subtree
        int l = distributeCandyUtil(root->left, ans);

        // Traverse right subtree
        int r = distributeCandyUtil(root->right, ans);

        // Update number of moves
        ans += abs(l) + abs(r);

        // Return number of moves to balance
        // current node
        return root->data + l + r - 1;
    }

    // Function to find the number of moves to
    // distribute all of the candies
    int distributeCandy(Node* root) {
        int ans = 0;

        distributeCandyUtil(root, ans);

        return ans;
    }
};