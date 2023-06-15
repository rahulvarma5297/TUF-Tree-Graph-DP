//* https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-ceil-in-bst\
//* https://youtu.be/KSsk8AhdOZA

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    // Your code here
    
    int ceilVal = -1;
    
    while(root){
        if(root->data == input){
            ceilVal = root->data;
            return ceilVal;
        }
        else if(root->data > input){
            ceilVal = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    
    return ceilVal;
}