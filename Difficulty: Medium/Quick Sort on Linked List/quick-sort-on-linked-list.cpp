//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends


class Solution {
  public:
  
   static void partition(Node *pivot, Node *&left, Node *&right){
        Node *temp=pivot->next;
        while(temp){
            Node *nxt = temp->next;
            if(temp->data<=pivot->data){
                temp->next=left;
                left=temp;
            }
            else{
                temp->next=right;
                right=temp;
            }
            temp=nxt;
        }
    }
    
    struct Node* quickSort(struct Node* head) {
        // code here
        if(!head or !head->next)    return head;
        Node *left=NULL,*right=NULL;
        
        partition(head,left,right);
        
        left = quickSort(left);
        right = quickSort(right);
        
        Node *traversal = left;
        while(traversal and traversal->next)    traversal=traversal->next;
            if(traversal)   traversal->next=head;
            else left=head;
            head->next=right;
            
            return left;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends