//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
       int count0 = 0,count1=0,count2=0;
       Node * temp = head;
       
       while(temp)
       {
           if(temp->data == 0)
           count0++;
           else if(temp->data == 1)
           count1++;
           else
           count2++;
           
           
           temp = temp->next;
       }
       
       Node * newHead=NULL;
       temp = NULL;
       while(count0--)
       {
           if(newHead==NULL)
           {
               newHead = new Node(0);
               temp = newHead;
           }
           else
           {
               temp->next = new Node(0);
               temp = temp->next;
           }
       }
       
       
        while(count1--)
       {
           if(newHead==NULL)
           {
               newHead = new Node(1);
               temp = newHead;
           }
           else
           {
               temp->next = new Node(1);
               temp = temp->next;
           }
       }
       
        while(count2--)
       {
           if(newHead==NULL)
           {
               newHead = new Node(2);
               temp = newHead;
           }
           else
           {
               temp->next = new Node(2);
               temp = temp->next;
           }
       }
       
       return newHead;
    }
};




//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends