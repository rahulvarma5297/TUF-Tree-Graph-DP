//* https://leetcode.com/problems/maximum-width-of-binary-tree/description/
//* https://youtu.be/ZbybYvcVLks

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        long long ans = INT_MIN;
        while(!q.empty()){
            int l = q.size();
            // long long lastInd = q.back().second, firstInd = q.front().second;
            long long lastInd, firstInd;
            long long mmin = q.front().second;
            for(int i = 0; i < l; ++i){
                TreeNode* temp = q.front().first;
                // long long curr_ind = q.front().second;
                long long curr_ind = q.front().second - mmin; // to convert index to zero based at that level
                q.pop();

                if(i == 0) firstInd = curr_ind;
                if(i == l-1) lastInd = curr_ind;

                if(temp->left) q.push({temp->left, 2*curr_ind+1});
                if(temp->right) q.push({temp->right, 2*curr_ind+2});
            }
            ans = max(ans, lastInd - firstInd + 1);
        }
        return ans;
    }
};