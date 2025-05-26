/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* temp=head;
        if(head->data>data){
            // in this case head node will change
            while(temp->next!=head){
                temp=temp->next;
            }
            Node* x=new Node(data);
            x->next=head;
            temp->next=x;
            return x;
        }
        else{
            while(temp->next->data<data && temp->next!=head){
                temp=temp->next;
            }
            Node* x=new Node(data);
            x->next=temp->next;
            temp->next=x;
            return head;
        }
    }
};