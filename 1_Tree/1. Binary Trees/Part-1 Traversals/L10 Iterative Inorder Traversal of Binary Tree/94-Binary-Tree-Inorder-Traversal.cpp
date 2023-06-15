//* https://leetcode.com/problems/binary-tree-inorder-traversal/description/
//* https://youtu.be/Z_NEgBgbRVI
//* https://youtu.be/lxTGsVXjwvM

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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inOrder(TreeNode* root)
    {
        //code here
        
        vector<int> ans;   
        TreeNode* node = root;
        stack<TreeNode*> st;
        
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                
                node = st.top();
                st.pop();
                
                ans.push_back(node->val);
                node = node->right;
            }
        }
        
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        //* Recursive Approach->
        // inorder(root, ans);
        // return ans;

        //* Iteratice Approach->
        return inOrder(root);
    }
};