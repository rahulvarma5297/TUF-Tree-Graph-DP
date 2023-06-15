//* https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//* https://youtu.be/3OXWEdlIGl4

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        //* Level Order Traversal->
        queue<TreeNode*> q;
        q.push(root);
        bool direction = true; // true-> L to R, false-> R to L

        while(!q.empty()){
            int sz = q.size();cout << sz;
            vector<int> level(sz);
            for(int i = 0; i < sz; i++){
                TreeNode* temp = q.front();
                q.pop();

                int index = (direction) ? i : (sz - 1 - i);
                level[index] = temp->val;

                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }

            direction = !direction;
            ans.push_back(level);
        }

        return ans;
    }
};