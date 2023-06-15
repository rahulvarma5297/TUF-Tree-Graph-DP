//* https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
//* https://youtu.be/C-2_uSRli8o

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        
        vector<vector<int>> ans = image;
        int initialColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        
        bfs(ans, image, sr, sc, newColor, n, m, initialColor);
        
        // dfs(ans, image, sr, sc, newColor, n, m, initialColor);
        
        return ans;
    }
    
    void bfs(vector<vector<int>>& ans, vector<vector<int>>& image,
                    int sr, int sc, int newColor, int n, int m, int iniColor){
        
        ans[sr][sc] = newColor;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        //* Directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            
            // Checking in all 4 directions
            for(int i = 0; i < 4; i++){

                int nRow = r + dr[i];
                int nCol = c + dc[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                    && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor){
                        
                    q.push({nRow, nCol});
                    ans[nRow][nCol] = newColor;
                }
            }
        }
    }
    
    void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, 
                int sr, int sc, int newColor, int n, int m, int iniColor){
        ans[sr][sc] = newColor;
        
        //* Directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // Checking in all 4 directions
        for(int i = 0; i < 4; i++){

            int nRow = sr + dr[i];
            int nCol = sc + dc[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor){
                    
                dfs(ans, image, nRow, nCol, newColor, n, m, iniColor);
            }
        }
    }
};