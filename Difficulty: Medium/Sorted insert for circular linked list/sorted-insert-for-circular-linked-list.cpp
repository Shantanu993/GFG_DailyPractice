//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *head) {
    if (head == NULL)
        return;

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}


// } Driver Code Ends

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data); 
        
        if (head->data > data) {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head; 
            last->next = newNode; 
            return newNode; 
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (true) {
            if (temp->data > data) {
                break;
            }
            prev = temp;
            temp = temp->next;

            if (temp == head) {
                break; 
            }
        }

        newNode->next = temp;
        if (prev) {
            prev->next = newNode; 
        }
        
        return head; 
    }
};






















//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make it circular
        Solution ob;
        Node *ans = ob.sortedInsert(head, x);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends