class Solution {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int count;
        bool end;
    };

    TrieNode* getNode() { return new TrieNode{{}, 0, false}; }

    void insert(TrieNode* root, const string& key) {
        TrieNode* temp = root;
        for (char ch : key) {
            if (!temp->children[ch])
                temp->children[ch] = getNode();
            temp = temp->children[ch];
            temp->count++;
        }
        temp->end = true;
    }

    string search(TrieNode* root, const string& key) {
        string res;
        TrieNode* temp = root;
        for (char ch : key) {
            res.push_back(ch);
            temp = temp->children[ch];
            if (temp->count == 1)
                break;
        }
        return res;
    }

  public:
    vector<string> findPrefixes(string arr[], int n) {
        TrieNode* root = getNode();
        for (int i = 0; i < n; ++i)
            insert(root, arr[i]);

        vector<string> res;
        for (int i = 0; i < n; ++i)
            res.push_back(search(root, arr[i]));
        return res;
    }
};