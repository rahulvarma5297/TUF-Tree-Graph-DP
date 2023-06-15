//* https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=diameter-of-binary-tree
//* https://youtu.be/Rezetez59Nk

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
    public:
    int height(Node* root, int& maxi){
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);
        
        maxi = max(maxi, lh+rh);
        
        return (1+max(lh, rh));
    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        
        int maxi = 0;
        height(root, maxi);
        return 1+maxi; // number of nodes in the path = 1 + number of edges
    }
};