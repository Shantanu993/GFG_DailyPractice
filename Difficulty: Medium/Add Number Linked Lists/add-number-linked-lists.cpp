class Solution {
  public:
  
    Node *rev(Node *h){
        if(!h or !h->next) return h;
        Node *p=nullptr,*n=nullptr,*c=h;
        
        while(c){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        
        return p;
    }
  
    Node* addTwoLists(Node* h1, Node* h2) {
        h1=rev(h1);
        h2=rev(h2);
        
        Node *d=new Node(-1);
        auto t=d;
        int c=0;
        
        while(c or h1 or h2){
            int s=c;
            if(h1) s+=h1->data,h1=h1->next;
            if(h2) s+=h2->data,h2=h2->next;
            t->next=new Node(s%10);
            c=s/10,t=t->next;
        }
        
        d=rev(d->next);
        t=d;
        
        while(t and t->data==0) t=t->next;
        return t;
    }
};