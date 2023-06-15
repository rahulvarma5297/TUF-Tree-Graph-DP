//* https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-a-binary-tree-in-vertical-order
//* https://youtu.be/q_a6lpbKJdw

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        // (node, (x, y))
        queue<pair<Node*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        // x->(y, {....})
        map<int, map<int, vector<int>>> node;

        while(!todo.empty()){
            auto temp = todo.front();
            todo.pop();
            Node* curr = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            node[x][y].push_back(curr->data);
            
            if(curr->left){
                todo.push({curr->left, {x-1, y+1}});
            }
            if(curr->right){
                todo.push({curr->right, {x+1, y+1}});
            }
        }

        for(auto i : node){
            for(auto j : i.second){
                ans.insert(ans.end(), j.second.begin(), j.second.end());
            }
        }

        return ans;
    }
};