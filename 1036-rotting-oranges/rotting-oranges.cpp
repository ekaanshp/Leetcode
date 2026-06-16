class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::deque<std::pair<int, int>> queue;
        int time = 0;
        int fresh = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    fresh++;
                }
                if(grid[r][c] == 2){
                    queue.push_back({r, c});
                }
            }
        }

        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!queue.empty() && fresh > 0){
            int queueSize = queue.size();
            for(int i = 0; i < queueSize; i++){
                auto [r, c] = queue.front();
                queue.pop_front();

               for (auto [dr, dc] : directions) {
                    int newR = r + dr;
                    int newC = c + dc;
                    
                    if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == 1) {
                        grid[newR][newC] = 2;
                        queue.push_back({newR, newC});
                        fresh--;
                    }
                }

            }
            time++;
        }

        if(fresh > 0){
            return -1;
        }
        else{
            return time;
        }
    }
};