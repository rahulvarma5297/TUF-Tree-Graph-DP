//* https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
//* https://youtu.be/SXKAD2svfmI

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){

// Your code goes here
    
    pre = NULL, suc = NULL;
    
    Node* temp = root;
    // calculating suc
    while(temp){
        if(temp->key <= key){
            temp = temp->right;
        }
        else{
            suc = temp;
            temp = temp->left;
        }
    }
    
    temp = root;
    // calculating pre
    while(temp){
        if(temp->key >= key){
            temp = temp->left;
        }
        else{
            pre = temp;
            temp = temp->right;
        }
    }
}