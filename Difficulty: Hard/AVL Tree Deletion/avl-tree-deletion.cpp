/* Node is as follows:

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

*/

int getheight(Node* root)
{
    if(!root)
    return 0;
    
    return root->height;
}

int getbalance(Node* root)
{
    if (!root) return 0;
    return getheight(root->left) - getheight(root->right);
}


// Right Rotation
Node* rightRotation(Node* root)
{
    Node* child = root->left;
    Node* childright = child->right;
    
    child->right = root;
    root->left = childright;
    
    // Update the height;
    root->height = 1+max(getheight(root->left), getheight(root->right));
    child->height = 1+max(getheight(child->left), getheight(child->right));
    
    return child;
}

// Left Rotation
Node* leftRotation(Node* root)
{
    Node* child = root->right;
    Node* childleft = child->left;
    
    child->left = root;
    root->right = childleft;
    
    // Update the height;
    root->height = 1+max(getheight(root->left), getheight(root->right));
    child->height = 1+max(getheight(child->left), getheight(child->right));
    
    return child;
}


Node* deleteNode(Node* root, int key)
{
    //add code here,
    if(!root)
    return NULL;
    
    if(key<root->data) // left side
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key>root->data)  // right side
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Leaf node
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // only one child exist
        else if(root->left && !root->right) // Left child
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right) // Right child
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Both child exist
        else
        {
            // Right side smallest element
            Node* curr = root->right;
            while(curr->left)
            {
                curr = curr->left;
            }
            
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    
    // Update the height
    root->height = 1+max(getheight(root->left), getheight(root->right));
    
    //Check the balance
    int balance = getbalance(root);
    
    // Left side
    if(balance > 1)
    {
        // LL
        if(root->left && getbalance(root->left) >= 0)
        return rightRotation(root);
        // LR
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // Right side
    if(balance < -1)
    {
        // RR
        if(root->right && getbalance(root->right) <= 0)
        return leftRotation(root);
        // RL
        else 
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else 
    return root;
    
}