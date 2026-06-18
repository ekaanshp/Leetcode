class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<bool>> islands(rows, std::vector<bool>(cols, false));
        int maxArea = 0;

        std::function<int(int, int, std::vector<std::vector<bool>>&, int&)> dfs =
        [&](int r, int c, std::vector<std::vector<bool>>& visited, int& area){
            if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] != 1){
                return area;
            }

            visited[r][c] = true;
            area++;

            dfs(r + 1, c, visited, area);
            dfs(r - 1, c, visited, area);
            dfs(r, c + 1, visited, area);
            dfs(r, c - 1, visited, area);
            return area;
        };

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    int area = 0;
                    int currentIslandArea = dfs(r, c, islands, area);
                    if(currentIslandArea > maxArea){
                        maxArea = currentIslandArea;
                    }
                }
            }
        }

        return maxArea;
    }
};