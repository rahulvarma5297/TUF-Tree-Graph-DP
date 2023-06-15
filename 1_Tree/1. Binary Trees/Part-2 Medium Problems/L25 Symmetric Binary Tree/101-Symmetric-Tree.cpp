//* https://leetcode.com/problems/symmetric-tree/
//* https://www.youtube.com/watch?v=nKggNAiEpBE&ab_channel=takeUforward

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
    bool dfs(TreeNode* leftSub, TreeNode* rightSub){

        // leftSub == NULL && rightSub == NULL
        if(leftSub == NULL || rightSub == NULL){
            return leftSub == rightSub;
        }

        // left && right && leftSub->val == rightSub->val
        return ((leftSub->val == rightSub->val) && 
                dfs(leftSub->left, rightSub->right) && 
                dfs(leftSub->right, rightSub->left));
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || dfs(root->left, root->right);
    }
};