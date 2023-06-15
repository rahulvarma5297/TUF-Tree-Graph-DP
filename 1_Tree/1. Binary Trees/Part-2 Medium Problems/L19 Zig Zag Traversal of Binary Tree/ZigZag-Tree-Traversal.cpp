//* https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=zigzag-tree-traversal
//* https://youtu.be/3OXWEdlIGl4


/*Structure of the node of the binary tree is as
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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
        
        if(root == NULL){return {  } ; }
        vector<int > ans ;
        queue<Node*> q ;
        q.push(root) ;
        bool flag = false ;
    
        while(!q.empty()){
            int size = q.size() ;
            vector<int> level ;
            for(int i=0 ; i < size ; i++){
                Node* node = q.front() ;
                q.pop() ;
                level.push_back(node->data) ;
    
                if(node->left != NULL) {q.push(node->left) ;}
                if(node->right != NULL) {q.push(node->right) ;}   
    
            }
            flag = !flag ;  
            if(flag == false){
                reverse(level.begin() , level.end()) ;           
            }
            for(int i = 0 ; i < level.size() ; i++){
                ans.push_back(level[i]) ;
            }
        }
        return ans ;
    }
};