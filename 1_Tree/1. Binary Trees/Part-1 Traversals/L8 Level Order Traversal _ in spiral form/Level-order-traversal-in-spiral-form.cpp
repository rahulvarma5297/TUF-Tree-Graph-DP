//* https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=level-order-traversal-in-spiral-form
//* https://youtu.be/EoAsWbO7sqg


vector<int> findSpiral(Node *root)
{
    //Your code here
    
    vector<int> res;
    if(root == NULL){
        return res;
    }
    
    int turn = 0;
    vector<vector<int>> ans;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int l = q.size();
        vector<int> level;
        
        for(int i = 1; i <= l; i++){
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        if(turn%2 == 0){
            reverse(level.begin(), level.end());
        }
        ans.push_back(level);
        turn++;
    }
    
    for(auto i : ans){
        for(auto j : i){
            res.push_back(j);
        }
    }
    
    return res;
}