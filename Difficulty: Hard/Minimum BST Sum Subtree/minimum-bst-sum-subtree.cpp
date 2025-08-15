// User function Template for C++

class Solution {
  public:
    int countNodes(Node* root){
        if(!root){
            return 0;
        }
        vector<int>v;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* f=q.front();
                q.pop();
                
                v.push_back(f->data);
                
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return v.size();
    }
    
    int sum(Node* root){
        if(!root){
            return 0;
        }
        return root->data+sum(root->left)+sum(root->right);
    }
    bool isBST( Node * root, long long l, long long h)
    {
         if(root==NULL)
        {
            return true;
        }
        if(root->data >= h || root->data <= l)return false;
        else
        {
            return isBST(root->left,l,root->data) && isBST(root->right,root->data,h);
        }
    }
    int minSubtreeSumBST(int target, Node *root) {
        int ans=INT_MAX;
        
        if(!root){
            return 0;
        }
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* f=q.front();
                q.pop();
                
                int s=sum(f);
                if(s==target and isBST(f,LONG_MIN,LONG_MAX)){
                    ans=min(ans,countNodes(f));
                }
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};