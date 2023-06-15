//* https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule
//* https://youtu.be/WAOfKpxYHR8

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        //code here
        
        vector<int> adj[n];

        // Creating Adjacency List
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        return using_kahnAlgo(n, adj);
    }
    
    vector<int> using_kahnAlgo(int V, vector<int> adj[]){
        
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++){
            for(int adjNode : adj[i]){
                indegree[adjNode]++; // calculating indegree of every node
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i); // pushing starting sources
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();

            topo.push_back(node);

            for(int adjNode : adj[node]){
                indegree[adjNode]--;

                // new start points
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        if(topo.size() == V){
            reverse(topo.begin(), topo.end());
            return topo;
        }

        return vector<int>{};
    }
};