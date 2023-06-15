//* https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-for-balanced-tree
//* https://youtu.be/Yt50Jfbd8Po

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

class Solution{
    public:
    int diff_height(Node* root){
        if(root == NULL){
            return 0;
        }

        int left_height = diff_height(root->left);
        int right_height = diff_height(root->right);

        if(left_height == -1 || right_height == -1){
            return -1;
        }

        if(abs(left_height - right_height) > 1){
            return -1;
        }

        return (1 + max(left_height, right_height));
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        
        return (diff_height(root) != -1);
    }
};
