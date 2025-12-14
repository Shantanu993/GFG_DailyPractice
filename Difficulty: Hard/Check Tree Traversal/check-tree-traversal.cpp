class Solution {
  public:
  
    class Node{
        public:
            int data;
            Node* left;
            Node* right;
            
            Node(int data) {
                this->data = data;
                left = right = NULL;
            }
    };
    
    int find(int pre[], int in[], int target, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(in[i] == target) return i;
        }
        return -1;
    }
    
    Node* buildTree(int pre[], int in[], int N, int inStart, int inEnd, int idx){
        if(inStart > inEnd) return NULL;
        
        Node* root1 = new Node(pre[idx]);
        int pos = find(pre,in,pre[idx], inStart, inEnd);
        if(pos==-1) return NULL;
        root1->left = buildTree(pre,in,N,inStart,pos-1,idx+1);
        root1->right = buildTree(pre,in,N,pos+1,inEnd,idx+(pos-inStart)+1);
        return root1;
    }
    
    Node* tree(int pre[], int in[], int N){
         return buildTree(pre,in,N,0,N-1,0);
      
    }
    
     void findPost(Node* root,vector<int>& ans) {
        if(!root) return;
        findPost(root->left,ans);
        findPost(root->right,ans);
        ans.push_back(root->data);
    }
    
    bool checktree(int pre[], int in[], int post[], int N) {
        // Your code goes here
        Node* root = tree(pre,in,N);
        if(!root) return false;
        vector<int> postAns;
        findPost(root,postAns);
        for(int i = 0; i<N; i++) {
            if(post[i] != postAns[i])
                return false;
        }
        return true;
    }
};