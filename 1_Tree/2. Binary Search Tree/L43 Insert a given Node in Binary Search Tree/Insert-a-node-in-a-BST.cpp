//* https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-a-bst
//* https://youtu.be/FiFiNvM29ps

// Function to insert a node in a BST.
Node* insert(Node* root, int Key) {
    // Your code here
    
    if(root == NULL){
        return (new Node(Key));
    }

    Node *curr = root;

    while(true){
        if(curr->data == Key){
            return root;
        }
        else if(curr->data < Key){
            if(curr->right != NULL) curr = curr->right; // move right
            else{
                curr->right = new Node(Key); // insert Node
                break;
            }
        }
        else{
            if(curr->left != NULL) curr = curr->left; // move left
            else{
                curr->left = new Node(Key); // insert Node
                break;
            }
        }
    }
        
    return root;
}