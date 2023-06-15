//* https://practice.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst
//* https://youtu.be/xm_W1ub-K-w

// Function to search a node in BST.

int floor(Node* root, int x) {
    // Code here
    
    int floorVal = -1;
    
    while(root){
        if(root->data == x){
            floorVal = root->data;
            return floorVal;
        }
        else if(root->data < x){
            floorVal = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    
    return floorVal;
}