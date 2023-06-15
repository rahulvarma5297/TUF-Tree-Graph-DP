//* https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=nodes-at-given-distance-in-binary-tree
//* https://youtu.be/i9ORlEy6EsI


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    Node* generateMap(Node* root, map<Node*, Node*>& mp, int target){
        mp[root] = NULL;

        queue<Node*> q;
        q.push(root);
        Node* start;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                Node* curr = q.front();
                q.pop();
                
                if(curr->data == target){
                    start = curr;
                }
                
                if(curr->left){
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        
        return start;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        
        //1. Create Child-Parent map for storing parent pointers
        map<Node*, Node*> parent_track;
        Node* start = generateMap(root, parent_track, target);


        //2. Traversing K distance radially in all three directions->
        queue<Node*> q;
        q.push(start);
        // visited map-> to keep track of visited nodes and not to revisited them again
        map<Node*, bool> visited;
        visited[start] = true;

        int curr_k = 0;

        while(!q.empty()){
            int sz = q.size();
            if(curr_k++ == k){
                break;
            }
            while(sz--){
                Node* curr = q.front();
                q.pop();

                // going left
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                // going right
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};