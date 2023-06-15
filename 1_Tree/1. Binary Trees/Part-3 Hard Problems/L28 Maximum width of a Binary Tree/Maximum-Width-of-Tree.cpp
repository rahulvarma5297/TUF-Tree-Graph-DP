//* https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://youtu.be/ZbybYvcVLks

/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        
        if(root == NULL){
            return 0;
        }

        queue<Node*> q;
        q.push(root);

        int ans = INT_MIN;
        while(!q.empty()){
            int l = q.size();
            ans = max(ans, l);
            for(int i = 0; i < l; ++i){
                Node* temp = q.front();
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};