//* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//* https://youtu.be/_-QHfMDde90

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{// both are not NULL
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        return dfs(root, p, q);
    }
};