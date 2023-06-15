//* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
//* https://www.youtube.com/watch?v=LgLRTaEMRVc&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=7Z6ivS-TA3k
//* https://www.youtube.com/watch?v=vm63HuIU7kw

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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //* Method 1-> Not space efficient but works for duplicate element cases
        // if(inorder.size() == 0 || postorder.size() == 0){
        //     return NULL;
        // }

        // TreeNode* root = new TreeNode(postorder.back());
        // if(postorder.size() == 1){
        //     return root;
        // }

        // int ind = find(begin(inorder), end(inorder), postorder.back()) - inorder.begin();

        // vector<int> left_inorder(begin(inorder), begin(inorder) + ind);
        // vector<int> right_inorder(begin(inorder) + ind + 1, end(inorder));

        // vector<int> left_postorder(begin(postorder), begin(postorder) + ind);
        // vector<int> right_postorder(begin(postorder) + ind, end(postorder) - 1);

        // root->left = buildTree(left_inorder, left_postorder);
        // root->right = buildTree(right_inorder, right_postorder);

        // return root;


        //* Method-2 Space Efficient but fails in duplicate element cases->
        // (val, index)
        map<int, int> mp;
        createMap(mp, inorder);
        TreeNode* root = createTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
    void createMap(map<int,int>& mp, vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
    }
    TreeNode* createTree(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int,int>& mp){
        if(ps > pe || is > ie){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pe]); //  postorder.back()
        int rootInd = mp[root->val];
        int rangeLeft = rootInd - is;

        // IMPORTANT
        root->left = createTree(postorder, ps, ps + rangeLeft - 1, inorder, is, rootInd - 1, mp);
        root->right = createTree(postorder, ps + rangeLeft, pe - 1, inorder, rootInd + 1, ie, mp);

        return root;
    }
};