//* https://leetcode.com/problems/binary-tree-maximum-path-sum/
//* https://youtu.be/WszrfSwMz58

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
    int dfs(TreeNode* root, int& maxi){
        if(root == NULL){
            return 0;
        }

        int left_MaxSum = max(0, dfs(root->left, maxi));
        int right_MaxSum = max(0, dfs(root->right, maxi));

        maxi = max(maxi, root->val + left_MaxSum + right_MaxSum);

        return (root->val + max(left_MaxSum, right_MaxSum));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};