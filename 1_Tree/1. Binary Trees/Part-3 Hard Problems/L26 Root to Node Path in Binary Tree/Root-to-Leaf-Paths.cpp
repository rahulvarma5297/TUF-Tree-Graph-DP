//* https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths
//* https://youtu.be/fmflMqVOC7k


bool isLeaf(Node* root){
    return (root->right==NULL && root->left==NULL);
}
void dfs(Node* root, vector<vector<int>>& ans, vector<int>& temp){
    
    if(isLeaf(root)){
        temp.push_back(root->data);
        ans.push_back(temp);
        temp.pop_back();
        return ;
    }
    
    temp.push_back(root->data);
    
    if(root->left){
        dfs(root->left, ans, temp);
    }
    if(root->right){
        dfs(root->right, ans, temp);
    }
    
    temp.pop_back();
}
vector<vector<int>> Paths(Node* root)
{
    // Code here
    
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
    
    vector<int> temp;
    dfs(root, ans, temp);
    return ans;
}
