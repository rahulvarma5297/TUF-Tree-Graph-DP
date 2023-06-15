//* https://leetcode.com/problems/binary-tree-preorder-traversal/description/
//* https://youtu.be/RlUu72JrOCQ
//* https://youtu.be/Bfqd8BsPVuw

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
    void pre(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }
    vector<int> preOrderIterative(TreeNode* root){
        vector<int> pre;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            pre.push_back(temp->val);
            
            if(temp->right != NULL){
                st.push(temp->right);
            }
            if(temp->left != NULL){
                st.push(temp->left);
            }
        }
        
        return pre;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        //* Recursive Approach->
        // pre(root, ans);
        // return ans;

        //* Iterative Approach using Stack->
        return preOrderIterative(root);
    }
};