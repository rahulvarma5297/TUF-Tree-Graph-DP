//* https://practice.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation


//{ Driver Code Starts
//Initial Template for Java


import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class Node{
    int val;
    Node left;
    Node right;
    
    Node(int val){
        this.val=val;
        left=null;
        right=null;
    }
}

class GFG {
    
    public static void traverseInorder(Node temp, ArrayList<Integer>inorder){
        if(temp!=null){
            traverseInorder(temp.left, inorder);
            inorder.add(temp.val);
            traverseInorder(temp.right, inorder);
        }
        return;
        
    }
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            ArrayList<Integer> v = new ArrayList<>();
            for(int i=0;i<7;i++){
                int x=sc.nextInt();
                v.add(x);
            }
            
            Node root=new Node(v.get(0));
            root.left = new Node(v.get(1));
            root.right = new Node(v.get(2));
            root.left.left = new Node(v.get(3));
            root.left.right = new Node(v.get(4));
            root.right.left = new Node(v.get(5));
            root.right.right = new Node(v.get(6));
            
            Node root0=new Node(v.get(0));
            Solution obj = new Solution();
            obj.createTree(root0, v);
            ArrayList<Integer> a = new ArrayList<>();
            traverseInorder(root0, a);
            
            ArrayList<Integer> b = new ArrayList<>();
            traverseInorder(root, b);
            
            if(a.equals(b)){
                System.out.println(1);
            }
            else{
                System.out.println(-1);
            }
        }
    }
}


// } Driver Code Ends


//User function Template for Java

class Solution{
    public static Node build_Tree(int ind, int n, ArrayList<Integer> v){
        if(ind >= n){
            return null;
        }
        
        Node root = new Node(v.get(ind));
        root.left = build_Tree(2*ind+1, n, v);
        root.right = build_Tree(2*ind+2, n, v);
        
        return root;
    }
    public static void createTree(Node root0, ArrayList<Integer> v ){
        // Code here
        int n = v.size();
        
        root0.left = build_Tree(1, n, v);;
        root0.right = build_Tree(2, n, v);
    }
}