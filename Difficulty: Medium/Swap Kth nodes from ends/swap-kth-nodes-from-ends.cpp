//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(NULL) {}
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void addressstore(vector<Node*>& arr, Node* head) {
    Node* temp = head;
    int i = 0;
    while (temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(const vector<Node*>& before, const vector<Node*>& after, int num, int k) {
    if (k > num)
        return true;

    for (int i = 0; i < num; i++) {
        if ((i == k - 1) || (i == num - k)) {
            if (!((before[k - 1] == after[num - k]) &&
                  (before[num - k] == after[k - 1]))) {
                return false;
            }
        } else {
            if (before[i] != after[i]) {
                return false;
            }
        }
    }
    return true;
}


// } Driver Code Ends


// Function to swap Kth node from beginning and end in a linked list.
class Solution {
  public:
    Node* swapKthNode(Node* head, int k) {
        // code here
        if (!head) return head;

        // Step 1: Count total nodes
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: If k is more than n, do nothing
        if (k > n) return head;

        // Step 3: If kth node from start and end are same, no need to swap
        if (2 * k - 1 == n) return head;

        // Step 4: Find kth node from start and its previous
        Node* prevX = NULL;
        Node* currX = head;
        for (int i = 1; i < k; i++) {
            prevX = currX;
            currX = currX->next;
        }

        // Step 5: Find kth node from end and its previous
        Node* prevY = NULL;
        Node* currY = head;
        for (int i = 1; i < n - k + 1; i++) {
            prevY = currY;
            currY = currY->next;
        }

        // Step 6: Swap the previous pointers' next
        if (prevX) prevX->next = currY;
        if (prevY) prevY->next = currX;

        // Step 7: Swap next pointers
        Node* tempNext = currX->next;
        currX->next = currY->next;
        currY->next = tempNext;

        // Step 8: Fix head if needed
        if (k == 1) head = currY;
        if (k == n) head = currX;

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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        int num = arr.size();
        vector<Node*> before(num);
        addressstore(before, head);

        Solution ob;
        head = ob.swapKthNode(head, k);

        vector<Node*> after(num);
        addressstore(after, head);

        if (check(before, after, num, k))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
// } Driver Code Ends