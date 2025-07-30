class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        this -> data = ch;
        
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Solution {
  public:
    // A : given string to search
    // B : vector of available strings
    TrieNode* root;
    Solution(){
        root = new TrieNode('\0');
    }
    
    
    void insert(string &word, TrieNode* root, int i=0){
        if(i == word.length()){
            root -> isTerminal = true;
            return ;
        }
        int index = word[i] - 'a';
        TrieNode* child;
        
        if(root -> children[index] != NULL){
            child = root ->children[index];
        }
        else{
            child = new TrieNode(word[i]);
            root -> children[index] = child;
        }
        insert(word, child, i+1);
    }
    bool search(string A, int start, vector<int> &dp){
        if(start == A.length()){
            return true;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        TrieNode* child = root;
        for(int i=start; i<A.length(); i++){
            int index = A[i] - 'a';
            
            if(child -> children[index] == NULL){
                break;
            }
            child= child -> children[index];
            if(child -> isTerminal){
                if(search(A, i+1, dp)){
                    return dp[start] = true;
                }
            }
        }
        return dp[start] = false;
    }
    int wordBreak(string A, vector<string> &B) {
        // code here
        for(int i=0; i<B.size(); i++){
            insert(B[i], root);
        }
        vector<int> dp(A.length(), -1);
        return search(A, 0, dp);
    }
};

