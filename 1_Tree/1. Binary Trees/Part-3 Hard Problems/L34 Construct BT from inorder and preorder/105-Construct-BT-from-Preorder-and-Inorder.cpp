//* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//* https://youtu.be/aZNaLrVebKQ

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
    void createMap(map<int,int>& mp, vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
    }
    TreeNode* createTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int,int>& mp){
        if(ps > pe || is > ie){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[ps]);
        int rootInd = mp[root->val];
        int rangeLeft = rootInd - is;

        // IMPORTANT
        root->left = createTree(preorder, ps + 1, ps + rangeLeft, inorder, is, rootInd - 1, mp);
        root->right = createTree(preorder, ps + rangeLeft + 1, pe, inorder, rootInd + 1, ie, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if(preorder.size() != inorder.size()){
        //     return NULL;
        // }

        //* Using same vectors-> (condition, if all elements are distinct, else map will only hold the last occured index)
        // // (val, index)
        // map<int, int> mp;
        // createMap(mp, inorder);
        // TreeNode* root = createTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        // return root;


        //* Creating separate vectors (passes cases of duplicate elements)
        if(inorder.size() == 0 || preorder.size() == 0){
            return NULL;
        }
        // dbg(inorder, preorder);

        TreeNode* root = new TreeNode(preorder.front());
        if(preorder.size() == 1){
            return root;
        }

        int rootInd = find(begin(inorder), end(inorder), root->val) - inorder.begin();

        vector<int> left_inorder(begin(inorder), begin(inorder) + rootInd);
        vector<int> right_inorder(begin(inorder) + rootInd + 1, end(inorder));

        vector<int> left_preorder(begin(preorder) + 1, begin(preorder) + rootInd + 1);
        vector<int> right_preorder(begin(preorder) + rootInd + 1, end(preorder));

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
    // void dbg(vector<int>& in, vector<int>& pre){
    //     cout << "inorder-> ";
    //     for(auto i : in){
    //         cout << i << " ";
    //     }
    //     cout<<endl;
    //     cout << "preorder-> ";
    //     for(auto i : pre){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    
};