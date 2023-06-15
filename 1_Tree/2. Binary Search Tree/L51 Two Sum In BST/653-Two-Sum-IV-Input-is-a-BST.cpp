//* https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//* https://youtu.be/ssL3sHwPeb4

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode*> myStack;
    bool reverse; // true->before, false->next
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();

        if(!reverse)
            pushAll(temp->right); // push all left nodes of right subtree
        else 
            pushAll(temp->left); // push all right nodes of left subtree
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
private:
    void pushAll(TreeNode* node){
        if(!reverse) // next
            for(; node != NULL; myStack.push(node), node = node->left);
        else // before
            for(; node != NULL; myStack.push(node), node = node->right);
    }
};

class Solution {
public:
    void generateInorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }

        generateInorder(root->left, inorder);
        inorder.push_back(root->val);
        generateInorder(root->right, inorder);
    }
    bool twoPointer(vector<int>& inorder, int k){
        int n = inorder.size();
        int l = 0, r = n-1;
        while(l < r){
            int currVal = inorder[l] + inorder[r];
            if(currVal == k){
                return true;
            }
            else if(currVal < k){
                l++;
            }
            else{
                r--;
            }
        }

        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        //* Method-1-> converting to inorder array, then apply two pointers
        // vector<int> inorder;
        // generateInorder(root, inorder);
        // return twoPointer(inorder, k);


        //* Method-2-> Using BST Iterators->
        // https://leetcode.com/problems/binary-search-tree-iterator/
        // https://youtu.be/D2jMcmxU4bs
        BSTIterator left(root, false), right(root, true);
        int i = left.next();
        int j = right.next();

        while(i < j){
            if(i + j == k){
                return true;
            }
            else if(i+j < k){
                i = left.next();
            }
            else{
                j = right.next();
            }
        }

        return false;
    }
};