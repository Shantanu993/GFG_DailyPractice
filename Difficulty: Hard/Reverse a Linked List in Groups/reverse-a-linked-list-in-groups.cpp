//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/


class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        //Base case 
        if(head == NULL){
            return NULL;
        }
        
        // Reverse the k nodes by the help of Iterative method
        node* previous = NULL;
        node* current = head;
        node* forward = NULL;
        int count = 0;
        
        while(count < k && current != NULL){
            forward = current->next;
            current->next = previous;
            
            // Update the value of (previous,current,forward)
            previous = current;
            current = forward;
            
            count++;
        }
        
        //reverse the further linkedlist by the help of Recursive call
        head->next = reverseIt(forward , k);
        
        return previous;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends