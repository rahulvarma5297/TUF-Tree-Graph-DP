//* https://practice.geeksforgeeks.org/problems/symmetric-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=symmetric-tree
//* https://youtu.be/nKggNAiEpBE

/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
public:
    bool dfs(Node* leftSub, Node* rightSub){

        // leftSub == NULL && rightSub == NULL
        if(leftSub == NULL || rightSub == NULL){
            return leftSub == rightSub;
        }

        // left && right && leftSub->val == rightSub->val
        return ((leftSub->data == rightSub->data) && dfs(leftSub->left, rightSub->right) && dfs(leftSub->right, rightSub->left));
    }
    
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
        
        return root == NULL || dfs(root->left, root->right);
    }
};