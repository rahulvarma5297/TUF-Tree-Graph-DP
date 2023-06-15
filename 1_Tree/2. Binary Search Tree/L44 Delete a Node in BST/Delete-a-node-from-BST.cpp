//* https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-a-node-from-bst
//* https://youtu.be/kouxiP_H5WE

Node* findLastRight(Node* root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}

Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    if(root->right == NULL){
        return root->left;
    }

    // in this case, i will reattach the right subtree to greatest node in left subtree making it the part of left subtree, removing the key node and return key nodes left subtree

    Node* rightTree = root->right;
    // going to extreme right of left subtree
    Node* leftLastRight = findLastRight(root->left);
    leftLastRight->right = rightTree;

    return root = root->left;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    
    if(root == NULL){
        return NULL;
    }
    if(root->data == X){
        return helper(root);
    }

    Node* dummy = root;
    while(root != NULL){
        if(root->data > X){
            // searching in left
            if(root->left != NULL && root->left->data == X){
            root->left = helper(root->left); // returning new root->left, after removal of key node
            }
            else{
                root = root->left;
            }
        }
        else{
            // root->val < X, searching right
            if(root->right != NULL && root->right->data == X){
                root->right = helper(root->right);
            }
            else{
                root = root->right;
            }
        }
    }

    return dummy;
}