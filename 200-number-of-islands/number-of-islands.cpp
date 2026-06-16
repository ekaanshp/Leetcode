class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        std::function<void(int, int)> dfs = [&](int r, int c){
            grid[r][c] = '0';

            if (r + 1 < rows && grid[r + 1][c] == '1') {
                dfs(r + 1, c);
            }
            if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                dfs(r - 1, c);
            }
            if (c + 1 < cols && grid[r][c + 1] == '1') {
                dfs(r, c + 1);
            }
            if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                dfs(r, c - 1);
            }
            return;
        };

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(i, j);
                }
            }
        }
        return islands;
    }
};