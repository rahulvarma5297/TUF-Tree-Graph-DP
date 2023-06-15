//* https://leetcode.com/problems/balanced-binary-tree/description/
//* https://youtu.be/Yt50Jfbd8Po

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
    int diff_height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left_height = diff_height(root->left);
        int right_height = diff_height(root->right);

        if(left_height == -1 || right_height == -1){
            return -1;
        }

        if(abs(left_height - right_height) > 1){
            return -1;
        }

        return (1 + max(left_height, right_height));
    }
    bool isBalanced(TreeNode* root) {
        return (diff_height(root) != -1);
    }
};