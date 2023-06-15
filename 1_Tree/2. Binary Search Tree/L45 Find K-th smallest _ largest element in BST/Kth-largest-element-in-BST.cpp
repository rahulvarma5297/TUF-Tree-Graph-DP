//* https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://youtu.be/9TJYWh0adfk

/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    Node* kthLargestNode(Node* root, int& k){
        if(root == NULL){
            return NULL;
        }

        Node* right = kthLargestNode(root->right, k); // go to extreme right bottom
        if(right != NULL){
            return right;
        }
        k--;
        if(k == 0){
            return root;
        }

        return kthLargestNode(root->left, k);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        
        Node* ans = kthLargestNode(root, K);

        return ans->data;
    }
};