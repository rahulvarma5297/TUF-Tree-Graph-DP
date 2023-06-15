//* https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
//* https://youtu.be/BtdgAys4yMk

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // checking boundaries
        for(int j = 0; j < m; j++){
            // first row
            if(mat[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, mat, vis, dr, dc, n, m);
            }
            // last row
            if(mat[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1, j, mat, vis, dr, dc, n, m);
            }
        }
        for(int i = 0; i < n; i++){
            // first column
            if(mat[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, mat, vis, dr, dc, n, m);
            }
            // last column
            if(mat[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, mat, vis, dr, dc, n, m);
            }
        }

        
        // updating mat
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
    
    void dfs(int row, int col, vector<vector<char>>& mat, 
            vector<vector<int>>& vis, int dr[], int dc[], int n, int m){
        
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && mat[nRow][nCol] == 'O' && !vis[nRow][nCol]){
                
                dfs(nRow, nCol, mat, vis, dr, dc, n, m);
            }
        }
    }
};