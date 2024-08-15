//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// User function template for C++
class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        string num = "";
        while(head != NULL){
            num += to_string(head->data);    
            head = head->next;
        }
        
        int i = num.size() - 1;
        while(i >= 0 && num[i] == '9'){
            num[i] = '0';
            i--;
        }
        
        if(i >= 0){
            num[i] += 1;
        }else{
            num = '1' + num;
        }
        
        
        int data = num[0] - '0';
        Node* ans = new Node(data);
        Node* temp = ans;
        for(int i = 1;i < num.size();i++){
            data = num[i] - '0';
            temp->next = new Node(data);
            temp = temp->next;
        }
        
        
        return ans;
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
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends