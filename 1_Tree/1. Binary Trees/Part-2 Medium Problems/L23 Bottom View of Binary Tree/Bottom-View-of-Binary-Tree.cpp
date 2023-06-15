//* https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bottom-view-of-binary-tree
//* https://youtu.be/0FtVY6I4pB8

//Function to return a list containing the bottom view of the given tree.

class Solution {
public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        // (node, x)
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        // (x, node->data)
        map<int, int> mp;
        
        while(!q.empty()){
            Node* temp = q.front().first;
            int x = q.front().second;
            q.pop();
            
            mp[x] = temp->data;
            
            if(temp->left){
                q.push({temp->left, x-1});
            }
            if(temp->right){
                q.push({temp->right, x+1});
            }
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};