//* https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges
//* https://youtu.be/yf3oUhkvqA0

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        return method_1(n, m, grid);
        
        // return method_2(n, m, grid);
    }
    
    int method_1(int n, int m , vector<vector<int>>& grid){
        
        int totalFresh = 0;
        queue<pair<pair<int,int>, int>> q; // {{row, col}, time};
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 1){
                    totalFresh++;
                }
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        int tm = 0; // max time;
        int rottened = 0;
        // BFS
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int t = node.second;
            
            tm = max(tm, t);
            
            for(int i = 0;  i < 4; i++){
                
                int nRow = r + dr[i];
                int nCol = c + dc[i];
            
                if(isValid(nRow, nCol, n, m, grid, vis)){
                    
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, t+1});
                    rottened++;
                }
            }
        }
        
        return (rottened == totalFresh ? tm : -1);
    }
    
    int method_2(int n, int m, vector<vector<int>>& grid){
        
        int totalFresh = 0, t = 0;
        queue<pair<int,int>> q; // {row, col};
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 1){
                    totalFresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        int rottened = 0;
        // BFS
        while(!q.empty()){
            int k = q.size();
            
            while(k--){
                auto node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;
                
                for(int i = 0;  i < 4; i++){
                    
                    int nRow = r + dr[i];
                    int nCol = c + dc[i];
                
                    if(isValid(nRow, nCol, n, m, grid, vis)){
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
            
            if(!q.empty()){
                t++;
                rottened += q.size();
            }
        }
        
        return rottened == totalFresh ? t : -1;
    }
    bool isValid(int row, int col, int n, int m, vector<vector<int>>& grid,
                    vector<vector<int>>& vis){
        
        return (row >= 0 && row < n && col >= 0 && col < m
                && grid[row][col] == 1 && !vis[row][col]);                    
    }
};