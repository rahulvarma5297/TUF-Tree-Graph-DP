//* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//* https://youtu.be/cX_kPV_foZc

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
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(root->val < p->val && root->val < q->val){
            return rec(root->right, p , q);
        }
        else if(root->val > p->val && root->val > q->val){
            return rec(root->left, p , q);
        }
        // else->
        return root;
    }
    TreeNode* iter(TreeNode* root, TreeNode* p, TreeNode* q){
        while(root){
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else{
                break;
            }
        }
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //* Recursive Approach->
        // return rec(root, p, q);

        //* Iterative Soln->
        return iter(root, p, q);
    }
};