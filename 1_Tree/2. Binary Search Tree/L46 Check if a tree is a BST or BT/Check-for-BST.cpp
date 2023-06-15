//* https://practice.geeksforgeeks.org/problems/check-for-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-for-bst
//* https://youtu.be/f-sj7I5oXEI

class Solution{
public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root){
        // Your code here
        
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(Node* root, long long minVal, long long maxVal){
        if(root == NULL) return true;

        if(root->data >= maxVal || root->data <= minVal) return false;

        return isValidBST(root->left, minVal, root->data) 
                            && isValidBST(root->right, root->data, maxVal);
    }
};