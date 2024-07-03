//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GFG {
    Node head;
    Node tail;

    public void addToTheLast(Node node) {
        if (head == null) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            tail = node;
        }
    }

    void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    /* Drier program to test above functions */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int N = sc.nextInt();
            GFG llist = new GFG();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < N; i++) {
                int a = sc.nextInt();
                llist.addToTheLast(new Node(a));
            }

            Solution ob = new Solution();
            head = ob.removeAllDuplicates(llist.head);
            llist.printList(head);

            t--;
        }
    }
}
// } Driver Code Ends


class Solution {
    public Node removeAllDuplicates(Node head) {
        // code here
        
        HashMap<Integer,Integer> dataMap = new HashMap<>();
        
        Node temp = head;
        
        while(temp != null) {
            dataMap.put(temp.data,dataMap.getOrDefault(temp.data,0)+1);
            temp = temp.next;
        }
        
        temp = head;
        Node prev = null;
        
        while(temp != null) {
            if(dataMap.get(temp.data) > 1) {
                temp = temp.next;
            }
            else {
                if(prev != null) {
                    prev.next = temp;
                }
                else {
                    head = temp;
                }
                
                prev = temp;
                temp = temp.next;
            }
        }
        
        prev.next = null;
        
        if(prev != null) {
            return head;
        }
        
        return null;
        
    }
}