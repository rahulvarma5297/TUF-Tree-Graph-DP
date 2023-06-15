//* https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=fixed-two-nodes-of-a-bst
//* https://youtu.be/ZWGW7FminDM

/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    Node *prev, *first, *middle, *last;

    void inorder(Node* root){
        if(root == NULL){
            return;
        }

        // go left
        inorder(root->left);

        // do something in between
        if(prev != NULL && root->data < prev->data){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;

        // go right
        inorder(root->right);
    }
    void correctBST( struct Node* root )
    {
        // add code here.
        
        // Optimised Approach->
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);
        if(first && last){
            // swap first and middle
            swap(first->data, last->data);
        }
        else if (first && middle){
            swap(first->data, middle->data);
        }
    }
};