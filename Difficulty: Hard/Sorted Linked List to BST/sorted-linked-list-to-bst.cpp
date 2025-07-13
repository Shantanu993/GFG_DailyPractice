class Solution {
private:
    LNode* mid(LNode* head, LNode* &prev) {
        LNode* slow = head;
        LNode* fast = head->next;
        prev = nullptr;

        while (fast && slow) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast)
            fast = fast->next;
        }
        return slow;
    }

    TNode* bst(LNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TNode(head->data);

        LNode* prev = nullptr;
        LNode* midNode = mid(head, prev);

        if (prev) prev->next = nullptr; // Break the list

        TNode* root = new TNode(midNode->data);
        root->left = bst(prev ? head : nullptr);
        root->right = bst(midNode->next);

        return root;
    }

public:
    TNode* sortedListToBST(LNode* head) {
        return bst(head);
    }
};