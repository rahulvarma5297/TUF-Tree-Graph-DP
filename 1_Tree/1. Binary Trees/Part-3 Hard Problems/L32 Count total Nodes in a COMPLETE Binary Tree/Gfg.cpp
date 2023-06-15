//* https://practice.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-nodes-in-a-binary-tree
//* https://youtu.be/u-yWemKGWO0

// User function Template for C++

class Solution {
public:
    // TC-> O(N)
    // int dfs(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }

    //     int left = dfs(root->left), right = dfs(root->right);

    //     return (1 + left + right);
    // }
    int countNodes(Node* root) {
        // Write your code here
        //* Brute Force
        // TC-> O(N)
        // return dfs(root);

        //* Using Properties of Complete Binary Tree
        //TC-> O((log N)^2)

        if(root == NULL){
            return 0;
        }

        int lh = leftHeight(root); // left height of root
        int rh = rightHeight(root); // right height of root

        if(lh == rh){
            return (1 << lh) - 1; // (2^h - 1) nodes
        }
        else{
            return (1 + countNodes(root->left) + countNodes(root->right));
        }
    }
    int leftHeight(Node* node){
        int height = 0;

        while(node){
            height++;
            node = node->left;
        }

        return height;
    }
    int rightHeight(Node* node){
        int height = 0;

        while(node){
            height++;
            node = node->right;
        }

        return height;
    }
};