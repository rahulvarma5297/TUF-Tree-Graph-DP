//* https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//* https://youtu.be/9TJYWh0adfk

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
    TreeNode* kthSmallestNode(TreeNode* root, int& k){
        if(root == NULL){
            return NULL;
        }

        TreeNode* left = kthSmallestNode(root->left, k); // go to extreme left bottom
        if(left != NULL){
            return left;
        }
        k--;
        if(k == 0){
            return root;
        }

        return kthSmallestNode(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = kthSmallestNode(root, k);

        return ans->val;
    }
};