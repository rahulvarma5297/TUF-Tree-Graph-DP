//* https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
//* https://youtu.be/BPlrALf1LDU

class Solution {
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V, 0);
        
        // connected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                // using bfs->
                // if(bfs(i, adj, vis)){
                //     return true;
                // }
                
                // using dfs->
                if(dfs(i, -1, adj, vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // bool bfs(int src, vector<int> adj[], vector<int>& vis){
        
    //     // {node, parent}
    //     queue<pair<int,int>> q;
    //     q.push({src, -1});
    //     vis[src] = 1;
        
    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int parent = q.front().second;
    //         q.pop();
            
    //         for(int i : adj[node]){
    //             if(!vis[i]){
    //                 q.push({i, node});
    //                 vis[i] = 1;
    //             }
    //             else if(parent != i){
    //                 // cycle exists
    //                 return true;
    //             }
    //         }
    //     }
        
    //     return false;
    // }
    
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis){
        
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                //* important
                if(dfs(i, node, adj, vis)){
                    return true;
                }
            }
            else if(parent != i){
                return true;
            }
        }
        
        return false;
    }
};