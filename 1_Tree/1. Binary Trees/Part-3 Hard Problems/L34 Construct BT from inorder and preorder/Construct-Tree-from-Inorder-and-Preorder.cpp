//* https://practice.geeksforgeeks.org/problems/construct-tree-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=construct-tree
//* https://youtu.be/aZNaLrVebKQ

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
public:
    
    // void createMap(map<int,int>& mp, int inorder[], int n){
    //     for(int i = 0; i < n; i++){
    //         mp[inorder[i]] = i;
    //     }
    // }
    // Node* createTree(int preorder[], int ps, int pe, int inorder[], int is, int ie, map<int,int>& mp){
    //     if(ps > pe || is > ie){
    //         return NULL;
    //     }

    //     Node* root = new Node(preorder[ps]);
    //     int rootInd = mp[root->data];
    //     int rangeLeft = rootInd - is;

    //     // IMPORTANT
    //     root->left = createTree(preorder, ps + 1, ps + rangeLeft, inorder, is, rootInd - 1, mp);
    //     root->right = createTree(preorder, ps + rangeLeft + 1, pe, inorder, rootInd + 1, ie, mp);

    //     return root;
    // }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        //* Method 1->
        //* Won't work as there are duplicates in the array, so we need to create seperate vectors and pass them
        // (data, index)
        // map<int, int> mp;
        // createMap(mp, in, n);
        // Node* root = createTree(pre, 0, n-1, in, 0, n-1, mp);
        
        
        //* Method 2->
        if(n == 0){
            return NULL;
        }
        
        Node* root = new Node(pre[0]);
        
        int rootInd = find(in, in+n, root->data) - in;
        int newLeftInorder[rootInd], newLeftPreorder[rootInd];
        for(int i = 0; i < rootInd; i++){
            newLeftInorder[i] = in[i];
            newLeftPreorder[i] = pre[i+1];
        }
        int newRightInorder[n-rootInd-1], newRightPreorder[n-rootInd-1];
        for(int i = rootInd+1; i < n; i++){
            newRightInorder[i-rootInd-1] = in[i];
            newRightPreorder[i-rootInd-1] = pre[i];
        }
        
        root->left = buildTree(newLeftInorder, newLeftPreorder, rootInd);
        root->right = buildTree(newRightInorder, newRightPreorder, n-rootInd-1);

        return root;
    }
    
};