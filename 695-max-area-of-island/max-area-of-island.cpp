class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<bool>> islands(rows, std::vector<bool>(cols, false));
        int maxArea = 0;

        std::function<int(int, int, std::vector<std::vector<bool>>&)> dfs =
        [&](int r, int c, std::vector<std::vector<bool>>& visited){
            if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] != 1){
                return 0;
            }

            visited[r][c] = true;

            return 1 + dfs(r + 1, c, visited) +
            dfs(r - 1, c, visited) +
            dfs(r, c + 1, visited) +
            dfs(r, c - 1, visited);
        };

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1 && !islands[r][c]){
                    int currentIslandArea = dfs(r, c, islands);
                    if(currentIslandArea > maxArea){
                        maxArea = currentIslandArea;
                    }
                }
            }
        }

        return maxArea;
    }
};