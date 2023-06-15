//* https://practice.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree
//* https://youtu.be/2r5wLmQfD6g


/*
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
class Solution {
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
    int burnTime(Node* root, int target)
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

        int time_elapsed = 0;

        while(!q.empty()){
            int sz = q.size();
            // is an unvisited tree burns-> newBurn = 1
            int newBurn = 0;
            while(sz--){
                Node* curr = q.front();
                q.pop();

                // going left
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                    newBurn = 1;
                }
                // going right
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                    newBurn = 1;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                    newBurn = 1;
                }
            }
            
            if(newBurn){
                time_elapsed++;
            }
        }

        return time_elapsed;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        return burnTime(root, target);
    }
};