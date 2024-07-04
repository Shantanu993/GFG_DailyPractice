//{ Driver Code Starts
import java.util.*;
import java.lang.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Rerrange
{
    static Node head;
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            addToTheLast(head);
            
            for(int i = 1; i < n; i++)
            {
                int data = sc.nextInt();
                addToTheLast(new Node(data));
            }
            GfG gfg = new GfG();
            Node node = gfg.rearrange(head);
            printList(node);
            System.out.println();
        }
    }
    
    public static void addToTheLast(Node node)
    {
        if(head == null)
        {
            head = node;
        }
        else
        {
            Node temp = head;
            while(temp.next != null)
              temp = temp.next;
              temp.next = node;
        }
    }
    
    public static void printList(Node node)
    {
        while(node != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }
}


// } Driver Code Ends


/*
The structure of linked list is the following

class Node
{
int data;
Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}
*/

class GfG 
{
    // Function to rearrange the linked list as required
    public static Node rearrange(Node head)
    {
        if (head == null || head.next == null) {
            return head; // If 0 or 1 node, no need to rearrange
        }
        
        // Step 1: Split the list into two halves
        Node slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Now slow is at the middle point
        Node secondHalf = slow.next;
        slow.next = null; // Split the list
        
        // Step 2: Reverse the second half
        secondHalf = reverse(secondHalf);
        
        // Step 3: Merge two halves alternately
        Node firstHalf = head;
        while (secondHalf != null) {
            Node temp1 = firstHalf.next;
            Node temp2 = secondHalf.next;
            
            firstHalf.next = secondHalf;
            secondHalf.next = temp1;
            
            firstHalf = temp1;
            secondHalf = temp2;
        }
        
        return head;
    }
    
    // Utility function to reverse a linked list
    private static Node reverse(Node head) {
        Node prev = null;
        Node current = head;
        while (current != null) {
            Node next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
}
