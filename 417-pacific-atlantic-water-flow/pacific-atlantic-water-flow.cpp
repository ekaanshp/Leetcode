class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        std::set<std::pair<int, int>> pacificReachable;
        std::set<std::pair<int, int>> atlanticReachable;

        std::function<void(int, int, std::set<std::pair<int, int>>&, int)> dfs = 
        [&](int r, int c, std::set<std::pair<int, int>>& visit, int prevHeight){
            if(visit.contains({r, c}) || r < 0 || r >= rows || c < 0 || c >= cols || heights[r][c] < prevHeight){
                return;
            }

            visit.insert({r, c});
            dfs(r + 1, c, visit, heights[r][c]);
            dfs(r - 1, c, visit, heights[r][c]);
            dfs(r, c + 1, visit, heights[r][c]);
            dfs(r, c - 1, visit, heights[r][c]);
        };

        for(int c = 0; c < cols; c++){
            dfs(0, c, pacificReachable, heights[0][c]);
            dfs(rows - 1, c, atlanticReachable, heights[rows - 1][c]);
        }

        for(int r = 0; r < rows; r++){
            dfs(r, 0, pacificReachable, heights[r][0]);
            dfs(r, cols - 1, atlanticReachable, heights[r][cols - 1]);
        }

        std::vector<std::vector<int>> result;
        for(auto cell : pacificReachable){
            if(atlanticReachable.contains(cell)){
                result.push_back({cell.first, cell.second});
            }
        }
        return result;
    }
};