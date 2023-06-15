//* https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
//* https://youtu.be/sWf7k1x9XR4

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
    TreeNode* prev;
    void rec(TreeNode* node){
        if(node == NULL){
            return;
        }

        rec(node->right);
        rec(node->left);
        node->right = prev;
        node->left = NULL;
        prev = node;
    }
    void iter(TreeNode* root){
        if(root == NULL){
            return;
        }

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }

            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = NULL;
        }
    }
    void morrisTraverseMethod(TreeNode* root){
        if(root == NULL){
            return;
        }

        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode *prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
    void flatten(TreeNode* root) {
        //* Recursive Method->
        // prev = NULL;
        // rec(root);

        //* Iterative Method using Stack->
        // iter(root);

        //* Optimised Method-> using concept of Morris Traversal
        morrisTraverseMethod(root);
    }
};