//* https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=boundary-traversal-of-binary-tree
//* https://youtu.be/0ca1nvR0be4

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
public:
    void addLeftBoundary(Node* root, vector<int>& res){
        Node* curr = root->left;
        
        while(curr){
            if(!isLeaf(curr)){
                res.push_back(curr->data);
            }
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }
    void addRightBoundary(Node* root, vector<int>& res){
        Node* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        
        // adding in reverse order
        for(int i = temp.size()-1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
    void addLeaves(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left){
            addLeaves(root->left, res);
        }
        if(root->right){
            addLeaves(root->right, res);
        }
    }
    bool isLeaf(Node* root){
        return !root -> left && !root -> right;
    }
    vector <int> boundary(Node *root){
        //Your code here
        
        vector<int> res;
        if(!root){
            return res;
        }
        // adding root
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};