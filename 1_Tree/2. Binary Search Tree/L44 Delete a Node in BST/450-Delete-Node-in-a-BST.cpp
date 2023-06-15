//* https://leetcode.com/problems/delete-node-in-a-bst/
//* https://youtu.be/kouxiP_H5WE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                // searching in left

                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left); // returning new root->left, after removal of key node
                }
                else{
                    root = root->left;
                }
            }
            else{
                // root->val < key, searching right

                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                }
                else{
                    root = root->right;
                }
            }
        }

        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }

        // in this case, i will reattach the right subtree to greatest node in left subtree making it the part of left subtree, removing the key node and return key nodes left subtree

        TreeNode* rightTree = root->right;
        // going to extreme right of left subtree
        TreeNode* leftLastRight = findLastRight(root->left);
        leftLastRight->right = rightTree;

        return root = root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
};