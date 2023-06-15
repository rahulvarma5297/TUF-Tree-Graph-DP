//* https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
//* https://youtu.be/ACzkVtewUYA

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // Creating Adjacency List
        vector<vector<int>> adjList(V);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        // code here
        
        return using_bfs(adjList, V);
        
        // return using_dfs(adjList, V);
    }
    
    int using_bfs(vector<vector<int>>& adjList, int V){
        
        int provinces = 0;
        vector<int> vis(V);

        // ensuring connected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto it : adjList[node]){
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

    int using_dfs(vector<vector<int>>& adjList, int V){

        int provinces = 0;
        vector<int> vis(V);

        // ensuring connected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adjList);
                provinces++;
            }
        }

        return provinces;
    }
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjList){
        vis[node] = 1;
        
        for(auto i : adjList[node]){
            if(!vis[i]){
                dfs(i, vis, adjList);
            }
        }
    }
};