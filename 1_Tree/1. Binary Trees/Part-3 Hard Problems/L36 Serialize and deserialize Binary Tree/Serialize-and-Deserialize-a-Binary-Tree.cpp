//* https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=serialize-and-deserialize-a-binary-tree
//* https://youtu.be/-YbXySKJsX8


/* A binary tree node has data, pointer to left child and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){
                ans.push_back(-1);
            }
            else{
                ans.push_back(curr->data);
            }

            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here

        if(A.size() == 0){
            return NULL;
        }
        
        

        Node* root = new Node(A[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            int data = A[i++];
            if(data == -1){
                curr->left = NULL;
            }
            else{
                Node* nodeLeft = new Node(data);
                curr->left = nodeLeft;
                q.push(nodeLeft);
            }

            data = A[i++];
            if(data == -1){
                curr->right = NULL;
            }
            else{
                Node* nodeRight = new Node(data);
                curr->right = nodeRight;
                q.push(nodeRight);
            }
        }

        return root;
    }

};