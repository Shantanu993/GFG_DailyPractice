class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        int A=a;
        int B=b;
        Node *first=new Node(0);
        first->next=head;
        A--;
        while(A){
            first=first->next;
            A--;
        }
        Node *prev=first;
        Node *curr=first->next;
        Node *second=curr;
        Node *front=NULL;
        int x=b-a+1;
        while(x){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            x--;
        }
        first->next=prev;
        second->next=curr;
        if(a==1){
            head=prev;
        }
        return head;
   }

};