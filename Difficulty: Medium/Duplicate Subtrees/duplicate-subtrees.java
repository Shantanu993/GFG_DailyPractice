//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node left, right;

    public Node(int data) { this.data = data; }
}

class GFG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    public static void preorder(Node root, List<Integer> temp) {
        if (root == null) return;
        temp.add(root.data);
        preorder(root.left, temp);
        preorder(root.right, temp);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.next());
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine();
            Node root = buildTree(s);
            Solution obj = new Solution();
            List<Node> res = obj.printAllDups(root);

            List<List<Integer>> ans = new ArrayList<>();

            for (int i = 0; i < res.size(); i++) {
                List<Integer> temp = new ArrayList<>();
                preorder(res.get(i), temp);
                ans.add(temp);
            }
            Collections.sort(ans,
                             (x, y)
                                 -> x.get(0) == y.get(0) ? x.size() - y.size()
                                                         : x.get(0) - y.get(0));

            for (int i = 0; i < ans.size(); i++) {
                for (int j = 0; j < ans.get(i).size(); j++) {
                    System.out.print(ans.get(i).get(j) + " ");
                }
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends




class Solution {
    public List<Node> printAllDups(Node root) {
        // code here
         String result = "";
        List<Node> list = new ArrayList<>();
        HashMap<String,Integer> map = new HashMap<>();
        pre_order(root,map,list);
        return list;
    }
    
    String pre_order(Node root,HashMap<String,Integer> map,List<Node> list){
        String result = "";
        if(root == null)
            result = "#";
        else if(root != null){
            result = pre_order(root.left,map,list)+","+root.data+","+pre_order(root.right,map,list);
            map.put(result,map.getOrDefault(result,0)+1);
            if(map.get(result) == 2)
                   list.add(root);
        }
      return result;    
    }
}