//* https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list
//* https://youtu.be/3oI-34aPMWM

class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<vector<int>> ans(V);
        
        for(int i = 0; i < V; i++){
            ans[i].push_back(i);
            
            for(int& x : adj[i]){
                ans[i].push_back(x);
            }
        }
        
        return ans;
    }
};