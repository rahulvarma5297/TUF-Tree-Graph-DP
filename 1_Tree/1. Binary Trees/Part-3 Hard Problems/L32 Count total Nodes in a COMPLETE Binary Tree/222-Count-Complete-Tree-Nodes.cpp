//* https://leetcode.com/problems/count-complete-tree-nodes/description/
//* https://youtu.be/u-yWemKGWO0

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
    // TC-> O(N)
    // int dfs(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }

    //     int left = dfs(root->left), right = dfs(root->right);

    //     return (1 + left + right);
    // }
    int countNodes(TreeNode* root) {
        //* Brute Force
        // TC-> O(N)
        // return dfs(root);

        //* Using Properties of Complete Binary Tree
        //TC-> O((log N)^2)

        if(root == NULL){
            return 0;
        }

        int lh = leftHeight(root); // left height of root
        int rh = rightHeight(root); // right height of root

        if(lh == rh){
            return (1 << lh) - 1; // (2^h - 1) nodes
        }
        else{
            return (1 + countNodes(root->left) + countNodes(root->right));
        }
    }
    int leftHeight(TreeNode* node){
        int height = 0;

        while(node){
            height++;
            node = node->left;
        }

        return height;
    }
    int rightHeight(TreeNode* node){
        int height = 0;

        while(node){
            height++;
            node = node->right;
        }

        return height;
    }
};