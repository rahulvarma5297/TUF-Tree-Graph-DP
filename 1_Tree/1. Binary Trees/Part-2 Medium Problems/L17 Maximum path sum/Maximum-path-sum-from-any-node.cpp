//* https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-path-sum-from-any-node
//* https://youtu.be/WszrfSwMz58

class Solution {
public:
    int dfs(Node* root, int& maxi){
        if(root == NULL){
            return 0;
        }

        int left_MaxSum = max(0, dfs(root->left, maxi));
        int right_MaxSum = max(0, dfs(root->right, maxi));

        maxi = max(maxi, root->data + left_MaxSum + right_MaxSum);

        return (root->data + max(left_MaxSum, right_MaxSum));
    }

    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // Your code goes here
        
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};