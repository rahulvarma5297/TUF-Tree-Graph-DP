//* https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
//* https://youtu.be/q_a6lpbKJdw

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        // (node, (x, y))
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        // x->(y, {....})
        map<int, map<int, multiset<int>>> node;

        while(!todo.empty()){
            auto temp = todo.front();
            todo.pop();
            TreeNode* curr = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            node[x][y].insert(curr->val);
            
            if(curr->left){
                todo.push({curr->left, {x-1, y+1}});
            }
            if(curr->right){
                todo.push({curr->right, {x+1, y+1}});
            }
        }

        for(auto i : node){
            vector<int> col;
            for(auto j : i.second){
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};