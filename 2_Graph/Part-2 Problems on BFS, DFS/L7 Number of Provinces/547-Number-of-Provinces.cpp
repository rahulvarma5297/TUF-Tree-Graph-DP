//* https://leetcode.com/problems/number-of-provinces/description/
//* https://youtu.be/ACzkVtewUYA

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // return using_bfs(isConnected);
        
        return using_dfs(isConnected);
    }

    int using_bfs(vector<vector<int>>& isConnected){
        
        // Creating Adjacency List
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int provinces = 0;
        vector<int> vis(n);

        // ensuring connected components
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto it : adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }

                provinces++;
            }
        }

        return provinces;
    }

    int using_dfs(vector<vector<int>>& isConnected){
        // Creating Adjacency List
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int provinces = 0;
        vector<int> vis(n);

        // ensuring connected components
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                provinces++;
            }
        }

        return provinces;
    }
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
    }
};