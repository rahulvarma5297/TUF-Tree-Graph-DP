//* https://practice.geeksforgeeks.org/problems/largest-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-bst
//* https://youtu.be/X0oXMdtUDwo

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue{
public:
    int minValue, maxValue, maxSize;
    NodeValue(int minValue, int maxValue, int maxSize){
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};
class Solution{
public:
    NodeValue largestBSTSubtreeHelper(Node* root){
        if(root == NULL){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        if(left.maxValue < root->data && root->data < right.minValue){
            return NodeValue(min(root->data, left.minValue), 
                            max(root->data, right.maxValue), 
                            1 + left.maxSize + right.maxSize);
        }
        else{
            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
        
        return largestBSTSubtreeHelper(root).maxSize;
    }
};