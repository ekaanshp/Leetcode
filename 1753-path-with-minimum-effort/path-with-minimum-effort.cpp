class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>,
        std::greater<std::tuple<int, int, int>>> minHeap;
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        minHeap.push({0, 0, 0});
        const std::vector<std::pair<int, int>> directions = {
            {-1,  0}, { 0,  1}, { 1,  0}, { 0, -1}};

        while(!minHeap.empty()){
            auto [diff, r, c] = minHeap.top();
            minHeap.pop();

            if(visited[r][c]){
                continue;
            }
            visited[r][c] = true;
            if(r == rows - 1 && c == cols - 1){
                return diff;
            }

            for(const auto& [dr, dc] : directions){
                int newR = r + dr;
                int newC = c + dc;

                if(newR < 0 || newC < 0 || newR >= rows || newC >= cols || visited[newR][newC]){
                    continue;
                }  
                int newDiff = std::max(std::abs(heights[r][c] - heights[newR][newC]), diff);
                minHeap.push({newDiff, newR, newC});
            }

        } 
        return 0;
    }
};