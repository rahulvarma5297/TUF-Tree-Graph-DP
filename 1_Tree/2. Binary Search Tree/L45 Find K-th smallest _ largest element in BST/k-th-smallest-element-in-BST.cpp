//* https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-k-th-smallest-element-in-bst
//* https://youtu.be/9TJYWh0adfk

/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    Node* kthSmallestNode(Node* root, int& k){
        if(root == NULL){
            return NULL;
        }

        Node* left = kthSmallestNode(root->left, k); // go to extreme left bottom
        if(left != NULL){
            return left;
        }
        k--;
        if(k == 0){
            return root;
        }

        return kthSmallestNode(root->right, k);
    }
    
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        
        Node* ans = kthSmallestNode(root, K);

        return (K > 0 ? -1 : ans->data);
    }
};