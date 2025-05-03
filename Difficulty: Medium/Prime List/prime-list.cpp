//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/


class Solution {
  public:
    Node *primeList(Node *head) 
    {
        const int MAX = 20000;
        vector<bool> isPrime(MAX + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= MAX; ++i) 
        {
            if (isPrime[i]) 
            {
                for (int j = i * i; j <= MAX; j += i) 
                {
                    isPrime[j] = false;
                }
            }
        }

        Node* curr = head;
        while (curr) {
            int val = curr->val;
            int dist = 0;
            while (true) 
            {
                if (val - dist >= 2 && isPrime[val - dist]) 
                {
                    curr->val = val - dist;
                    break;
                }
                if (val + dist <= MAX && isPrime[val + dist]) 
                {
                    curr->val = val + dist;
                    break;
                }
                ++dist;
            }
            curr = curr->next;
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
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends