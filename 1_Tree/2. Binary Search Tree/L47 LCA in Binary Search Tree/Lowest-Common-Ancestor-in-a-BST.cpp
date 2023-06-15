//* https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=lowest-common-ancestor
//* https://youtu.be/cX_kPV_foZc

//Function to find the lowest common ancestor in a BST.
Node* rec(Node* root, int p, int q){
    if(root == NULL){
        return NULL;
    }

    if(root->data < p && root->data < q){
        return rec(root->right, p , q);
    }
    else if(root->data > p && root->data > q){
        return rec(root->left, p , q);
    }
    // else->
    return root;
}
Node* iter(Node* root, int p, int q){
    while(root){
        if(root->data < p && root->data < q){
            root = root->right;
        }
        else if(root->data > p && root->data > q){
            root = root->left;
        }
        else{
            break;
        }
    }
    
    return root;
}
Node* LCA(Node *root, int n1, int n2)
{
    //Your code here

    //* Recursive Approach->
    // return rec(root, n1, n2);
    
    //* Iterative Soln->
    return iter(root, n1, n2);
}