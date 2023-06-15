//* https://leetcode.com/problems/binary-tree-paths/
//* https://youtu.be/fmflMqVOC7k

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
    bool isLeaf(TreeNode* root){
        return !(root->left) && !(root->right);
    }
    void dfs(string s, TreeNode* root, vector<string>& ans){
        if(isLeaf(root)){
            s += to_string(root->val);
            ans.push_back(s);
        }

        string temp = to_string(root->val);
        if(root->left){
            dfs(s+temp+"->", root->left, ans);
        }
        if(root->right){
            dfs(s+temp+"->", root->right, ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL){
            return ans;
        }
        string s = to_string(root->val);
        if(isLeaf(root)){
            ans.push_back(s);
            return ans;
        }

        dfs("", root, ans);
        return ans;
    }
};