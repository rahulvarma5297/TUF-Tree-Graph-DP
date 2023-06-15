//* https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postorder-traversal-iterative
//* https://youtu.be/2YBhNLodD8Q
//* https://youtu.be/NzIGLLwZBS8

class Solution{
    public:
    vector<int> using_two_stack(Node* node, vector<int>& ans){
        stack<Node*> st1;
        stack<int> st2;
        st1.push(node);
        
        while(!st1.empty()){
            Node* temp = st1.top();
            st1.pop();
            st2.push(temp->data);
            
            if(temp->left != NULL){
                st1.push(temp->left);
            }
            if(temp->right != NULL){
                st1.push(temp->right);
            }
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        
        return ans;
    }
    vector<int> using_one_stack(Node* node, vector<int>& ans){
        stack<Node*> st;
        Node* curr = node;
        
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                Node* temp = st.top()->right;
                
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        
        return ans;
    }
    vector<int> postOrder(Node* node) {
        // code here
        
        vector<int> ans;
        if(node == NULL){
            return ans;
        }
        
        // Using Two Stacks->
        // return using_two_stack(node, ans);
        
        //* Using One Stack->
        return using_one_stack(node, ans);
    }
};