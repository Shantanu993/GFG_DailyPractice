//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p)
        : coeff(c)
        , pow(p)
        , next(nullptr) {}
};

void append(Node*& head_ref, Node*& tail_ref, int new_data, int new_data1) {
    Node* new_node = new Node(new_data, new_data1);

    if (head_ref == nullptr)
        head_ref = new_node;
    else
        tail_ref->next = new_node;
    tail_ref = new_node;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next != nullptr)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node *addPolynomial(Node *l1, Node *l2) {
        if(l1==NULL &&l2==NULL)return NULL; //base conditions
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        Node *t1=l1,*t2=l2,*newlist=NULL,*k,*ptr;
        int coeff_sum,pow_term;
        while(t1!=NULL && t2!=NULL) //when both are not null
        {
            if(t1->pow==t2->pow){
                coeff_sum=t1->coeff+t2->coeff;
                pow_term=t1->pow;
                t1=t1->next;
                t2=t2->next;
            }
            else if(t1->pow>t2->pow) //the term in eq1 is greater than eq2
            {
                coeff_sum=t1->coeff;
                pow_term=t1->pow;
                t1=t1->next;
            }
            else
            {
                coeff_sum=t2->coeff; //the term in eq2 is greater than eq1
                pow_term=t2->pow;
                t2=t2->next;
            }
            
            ptr=(Node*)malloc(sizeof(Node)); 
            ptr->coeff=coeff_sum;
            ptr->pow=pow_term;
            if(newlist==NULL){
                newlist=ptr;
                k=ptr;
                
            }
            else
            {
                k->next=ptr;
                k=ptr;
            }
        }
        while(t1!=NULL)  //done for remaining elements of eq1
        {
            ptr=(Node*)malloc(sizeof(Node)); 
            ptr->coeff=t1->coeff;
            ptr->pow=t1->pow;
            if(newlist==NULL){
                newlist=ptr;
                k=ptr;
                
            }
            else
            {
                k->next=ptr;
                k=ptr;
            }
            t1=t1->next;
        }
         while(t2!=NULL)   //done for remaining elements of eq2
        {
             ptr=(Node*)malloc(sizeof(Node));
            ptr->coeff=t2->coeff;
            ptr->pow=t2->pow;
            if(newlist==NULL){
            newlist=ptr;
            k=ptr;
                
            }
            else
            {
                k->next=ptr;
                k=ptr;
            }
            t2=t2->next;
        }
        return newlist;    }
};


//{ Driver Code Starts.

/* Driver program to test above function */
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        Node *poly1 = nullptr, *poly2 = nullptr, *tail1 = nullptr, *tail2 = nullptr;
        int n = arr1.size();
        for (int i = 0; i < n; i += 2) {
            int x = arr1[i], y = arr1[i + 1];
            append(poly1, tail1, x, y);
        }

        vector<int> arr2;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss1(input);
        while (ss1 >> number) {
            arr2.push_back(number);
        }

        int m = arr2.size();
        for (int i = 0; i < m; i += 2) {
            int x = arr2[i], y = arr2[i + 1];
            append(poly2, tail2, x, y);
        }

        Solution obj;
        Node* sum = obj.addPolynomial(poly1, poly2);
        printList(sum);
    }

    return 0;
}

// } Driver Code Ends