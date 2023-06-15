//* https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1
//* https://youtu.be/lxTGsVXjwvM

class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        Node* node = root;
        stack<Node*> st;
        
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                
                node = st.top();
                st.pop();
                
                ans.push_back(node->data);
                node = node->right;
            }
        }
        
        return ans;
    }
};