//* https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-a-node-in-bst
//* https://youtu.be/KcNt6v_56cc

// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    
    while(root != NULL && root->data != x){
        root = (root->data < x) ? root->right : root->left;
    }
    return root;
}
