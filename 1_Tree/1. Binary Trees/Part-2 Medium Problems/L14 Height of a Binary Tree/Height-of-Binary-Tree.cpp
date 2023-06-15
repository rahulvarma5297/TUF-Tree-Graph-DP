//* https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=height-of-binary-tree
//* https://youtu.be/eD3tmO66aBA

/*
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
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        
        if(node == NULL){
            return 0;
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return (1+ max(leftHeight, rightHeight));
    }
};