//* https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
//* https://youtu.be/i9ORlEy6EsI

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
    void generateMap(TreeNode* root, map<TreeNode*, TreeNode*>& mp){
        mp[root] = NULL;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left){
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //1. Create Child-Parent map for storing parent pointers
        map<TreeNode*, TreeNode*> parent_track;
        generateMap(root, parent_track);


        //2. Traversing K distance radially in all three directions->
        queue<TreeNode*> q;
        q.push(target);
        // visited map-> to keep track of visited nodes and not to revisited them again
        map<TreeNode*, bool> visited;
        visited[target] = true;

        int curr_k = 0;

        while(!q.empty()){
            int sz = q.size();
            if(curr_k++ == k){
                break;
            }
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();

                // going left
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                // going right
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};