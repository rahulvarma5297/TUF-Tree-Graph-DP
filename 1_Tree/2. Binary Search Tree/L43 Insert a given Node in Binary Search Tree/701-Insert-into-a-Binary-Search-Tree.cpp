//* https://leetcode.com/problems/insert-into-a-binary-search-tree/
//* https://youtu.be/FiFiNvM29ps

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return (new TreeNode(val));
        }

        TreeNode *curr = root;

        while(true){
            if(curr->val <= val){
                if(curr->right != NULL) curr = curr->right; // move right
                else{
                    curr->right = new TreeNode(val); // insert Node
                    break;
                }
            }
            else{
                if(curr->left != NULL) curr = curr->left; // move left
                else{
                    curr->left = new TreeNode(val); // insert Node
                    break;
                }
            }
        }
        
        return root;
    }
};