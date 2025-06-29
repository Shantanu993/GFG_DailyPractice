/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    int mini=-1;
    if(!root)
        return 0;
     while(root){ 
    if(root->data>=input){
        
        mini=root->data;
        root=root->left;
    }
    else
        root=root->right;
     }
    return mini;
}