//* https://leetcode.com/problems/maximum-depth-of-binary-tree/
//* https://youtu.be/eD3tmO66aBA

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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        else{
            int leftHeight = maxDepth(root-> left);
            int rightHeight = maxDepth(root-> right);

            return 1 + max(leftHeight, rightHeight);
        }
    }
};