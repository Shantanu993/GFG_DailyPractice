class Solution {
public:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };

    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int findMaxXOR(TrieNode* root, int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->children[toggledBit]) {
                maxXOR += (1 << i);
                node = node->children[toggledBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }

    int maxSubarrayXOR(int N, int arr[]) {
        TrieNode* root = new TrieNode();
        insert(root, 0);
        int maxXOR = 0;
        int prefixXOR = 0;

        for (int i = 0; i < N; i++) {
            prefixXOR ^= arr[i];
            insert(root, prefixXOR);
            maxXOR = max(maxXOR, findMaxXOR(root, prefixXOR));
        }

        return maxXOR;
    }
};