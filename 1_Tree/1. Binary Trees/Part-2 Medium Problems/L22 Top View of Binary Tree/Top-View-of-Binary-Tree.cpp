//* https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=top-view-of-binary-tree
//* https://youtu.be/Et9OCDNvJ78

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
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
            
            if(mp.find(x) == mp.end()){
                mp[x] = temp->data;
            }
            
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