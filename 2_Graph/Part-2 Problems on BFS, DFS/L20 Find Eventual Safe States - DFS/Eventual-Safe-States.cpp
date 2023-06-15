//* https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
//* https://youtu.be/uRbJ1OF9aYM

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V, 0), pathvis(V, 0), check(V, 0), ans;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathvis, check);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    bool dfs(int node, vector<int> adj[], vector<int>& vis, 
            vector<int>& path, vector<int>& check){
                
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adj, vis, path, check) == true){
                    check[adjNode] = 0;
                    return true;
                }
            }
            else if(path[adjNode]){
                check[adjNode] = 0;
                return true;
            }
        }
        
        check[node] = 1;
        path[node] = 0;
        return false;
    }
};