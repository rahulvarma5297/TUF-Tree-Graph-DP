//* https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=lowest-common-ancestor-in-a-binary-tree
//* https://youtu.be/_-QHfMDde90

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 

        if(root == NULL || root->data == n1 || root->data == n2){
            return root;
        }
        
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
        
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
};