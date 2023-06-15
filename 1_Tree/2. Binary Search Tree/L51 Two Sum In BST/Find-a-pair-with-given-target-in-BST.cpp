//* https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-a-pair-with-given-target-in-bst
//* https://youtu.be/D2jMcmxU4bs

/*Complete the function below
Node is as follows
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

class BSTIterator {
private:
    stack<Node*> myStack;
    bool reverse; // true->before, false->next
public:
    BSTIterator(Node* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        Node* temp = myStack.top();
        myStack.pop();

        if(!reverse)
            pushAll(temp->right); // push all left nodes of right subtree
        else 
            pushAll(temp->left); // push all right nodes of left subtree
        return temp->data;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
private:
    void pushAll(Node* node){
        if(!reverse) // next
            for(; node != NULL; myStack.push(node), node = node->left);
        else // before
            for(; node != NULL; myStack.push(node), node = node->right);
    }
};

class Solution{
public:
    void generateInorder(Node* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }

        generateInorder(root->left, inorder);
        inorder.push_back(root->data);
        generateInorder(root->right, inorder);
    }
    bool twoPointer(vector<int>& inorder, int k){
        int n = inorder.size();
        int l = 0, r = n-1;
        while(l < r){
            int currData = inorder[l] + inorder[r];
            if(currData == k){
                return true;
            }
            else if(currData < k){
                l++;
            }
            else{
                r--;
            }
        }

        return false;
    }
    
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target){
    //add code here.
    
        //* Method-1-> converting to inorder array, then apply two pointers
        // vector<int> inorder;
        // generateInorder(root, inorder);
        // return twoPointer(inorder, target);


        //* Method-2-> Using BST Iterators->
        // https://leetcode.com/problems/binary-search-tree-iterator/
        // https://youtu.be/D2jMcmxU4bs
        BSTIterator left(root, false), right(root, true);
        int i = left.next();
        int j = right.next();

        while(i < j){
            if(i + j == target){
                return true;
            }
            else if(i+j < target){
                i = left.next();
            }
            else{
                j = right.next();
            }
        }

        return false;
    }
};