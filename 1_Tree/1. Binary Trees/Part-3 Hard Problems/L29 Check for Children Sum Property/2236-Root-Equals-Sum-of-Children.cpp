//* https://leetcode.com/problems/root-equals-sum-of-children/
//* https://youtu.be/fnmisPM6cVo

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
    // void reorder(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }

    //     // going down
    //     int child = 0;
    //     if(root->left) child += root->left->val;
    //     if(root->right) child += root->right->val;

    //     if(child > root->val){
    //         root->val = child;
    //     }
    //     else{
    //         if(root->left) root->left->val = root->val;
    //         if(root->right) root->right->val = root->val;
    //     }

    //     checkTree(root->left);
    //     checkTree(root->right);

    //     // going up
    //     int tot = 0;
    //     if(root->left) tot += root->left->val;
    //     if(root->right) tot += root->right->val;
    //     if(root->left || root->right){
    //         root->val = tot;
    //     }
    // }

    bool isLeaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    bool checkTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if(isLeaf(root)){
            return true;
        }

        int lval = 0, rval = 0;
        if(root->left) lval = root->left->val;
        if(root->right) rval = root->right->val;

        return root->val == (lval+rval) && checkTree(root->left) && checkTree(root->right);
    }
};