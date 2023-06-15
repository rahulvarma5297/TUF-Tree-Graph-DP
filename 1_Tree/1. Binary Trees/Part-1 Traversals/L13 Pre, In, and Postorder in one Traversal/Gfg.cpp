//* https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postorder-traversal-iterative
//* https://youtu.be/ySp2epYvgTE

vector<int> oneTraversal(Node *root)
{
    vector<int> pre, in, post;

    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        { // (it.second == 1)
            post.push_back(it.first->data);
        }
    }

    return post;
}
vector<int> postOrder(Node *node)
{
    // code here

    vector<int> ans;
    if (node == NULL)
    {
        return ans;
    }

    // Using Two Stacks->
    // return using_two_stack(node, ans);

    //* Using One Stack->
    // return using_one_stack(node, ans);

    //* Preorder, Inorder, Postorder in One Traversal
    return oneTraversal(node);
}