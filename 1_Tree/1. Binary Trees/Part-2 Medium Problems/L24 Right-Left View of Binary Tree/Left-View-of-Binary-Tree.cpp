//* https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=left-view-of-binary-tree
//* https://youtu.be/KV4mRzTjlAk

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

void dfs(Node* root, int level, vector<int>& ans){
    if(root == NULL){
        return;
    }

    if(ans.size() == level){
        ans.push_back(root->data);
    }

    dfs(root->left, level + 1, ans);
    dfs(root->right, level + 1, ans);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here

    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
}