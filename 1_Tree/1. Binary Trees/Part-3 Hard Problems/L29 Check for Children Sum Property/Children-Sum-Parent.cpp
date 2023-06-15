//* https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
//* https://youtu.be/fnmisPM6cVo


/*Complete the function below

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
    bool isLeaf(Node* root){
        return (root->left == NULL && root->right == NULL);
    }
    
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        if(root == NULL){
            return true;
        }
        if(isLeaf(root)){
            return true;
        }
        
        int ldata = 0, rdata = 0;
        if(root->left) ldata = root->left->data;
        if(root->right) rdata = root->right->data;
        
        return root->data == (ldata+rdata) && isSumProperty(root->left) && isSumProperty(root->right);
    }
};