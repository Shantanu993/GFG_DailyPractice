// Function to merge two halves of the list
class Solution {
  public:
    DLLNode *merge(DLLNode *first, DLLNode *second) {
        // Base cases when either of two halves is null
        if (!first)
            return second;
        if (!second)
            return first;

        // Comparing data in both halves and storing the smaller in result
        if (first->data < second->data) {
            first->next = merge(first->next, second);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        } else {
            second->next = merge(first, second->next);
            second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }

    // Function to split the list into two halves
    DLLNode *splitList(DLLNode *head) {
        if (!head || !head->next)
            return NULL;

        DLLNode *fast = head, *slow = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        DLLNode *temp = slow->next;
        slow->next = NULL;
        return temp;
    }

    // Function to sort the given doubly linked list using Merge Sort
    DLLNode *sortDoubly(DLLNode *head) {
        if (!head || !head->next)
            return head;

        DLLNode *second = splitList(head);
        head = sortDoubly(head);
        second = sortDoubly(second);

        return merge(head, second);
    }
};