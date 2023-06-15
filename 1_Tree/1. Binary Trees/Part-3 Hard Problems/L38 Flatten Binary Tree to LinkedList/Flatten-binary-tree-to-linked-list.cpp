//* https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flatten-binary-tree-to-linked-list
//* https://youtu.be/sWf7k1x9XR4

class Solution
{
public:
    Node* prev;
    void rec(Node* node){
        if(node == NULL){
            return;
        }

        rec(node->right);
        rec(node->left);
        node->right = prev;
        node->left = NULL;
        prev = node;
    }
    void iter(Node* root){
        if(root == NULL){
            return;
        }

        stack<Node*> st;
        st.push(root);

        while(!st.empty()){
            Node* curr = st.top();
            st.pop();

            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }

            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = NULL;
        }
    }
    void morrisTraverseMethod(Node* root){
        if(root == NULL){
            return;
        }

        Node* curr = root;

        while(curr != NULL){
            if(curr->left != NULL){
                Node *prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
    void flatten(Node *root)
    {
        //code here
        
        //* Recursive Method->
        // prev = NULL;
        // rec(root);

        //* Iterative Method using Stack->
        // iter(root);

        //* Optimised Method-> using concept of Morris Traversal
        morrisTraverseMethod(root);
    }
};