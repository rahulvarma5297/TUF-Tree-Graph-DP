//* https://leetcode.com/problems/recover-binary-search-tree/description/
//* https://youtu.be/ZWGW7FminDM

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
    TreeNode *prev, *first, *middle, *last;

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        // go left
        inorder(root->left);

        // do something in between
        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;

        // go right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        // Optimised Approach->
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){
            // swap first and middle
            swap(first->val, last->val);
        }
        else if (first && middle){
            swap(first->val, middle->val);
        }
    }
};