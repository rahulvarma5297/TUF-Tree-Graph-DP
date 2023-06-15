//* https://leetcode.com/problems/binary-tree-postorder-traversal/description/
//* https://youtu.be/COQOU6klsBg
//* https://youtu.be/2YBhNLodD8Q
//* https://youtu.be/NzIGLLwZBS8

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
    void post(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> using_two_stack(TreeNode* node, vector<int>& ans){
        stack<TreeNode*> st1;
        stack<int> st2;
        st1.push(node);
        
        while(!st1.empty()){
            TreeNode* temp = st1.top();
            st1.pop();
            st2.push(temp->val);
            
            if(temp->left != NULL){
                st1.push(temp->left);
            }
            if(temp->right != NULL){
                st1.push(temp->right);
            }
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        
        return ans;
    }
    vector<int> using_one_stack(TreeNode* node, vector<int>& ans){
        stack<TreeNode*> st;
        TreeNode* curr = node;
        
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        //* Recursive Approach->
        // post(root, ans);
        // return ans;

        // Using Two Stacks->
        // return using_two_stack(root, ans);

        // Using One Stacks->
        return using_one_stack(root, ans);
    }
};