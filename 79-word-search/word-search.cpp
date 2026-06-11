class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        
        std::function<bool(int, int, int)> dfs = [&](int r, int c, int i) -> bool{
            if(i == word.size()){
                return true;
            }

            if(r < 0 || c < 0 || r >= rows || c >= cols || word[i] != board[r][c] || visited[r][c]){
                return false;
            }

            visited[r][c] = true;
            bool result = dfs(r + 1, c, i + 1) || dfs(r - 1, c, i + 1) 
            || dfs(r, c + 1, i + 1) || dfs(r, c - 1, i + 1);
            visited[r][c] = false;

            return result;
        };

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(dfs(r, c, 0)){
                    return true;
                }
            }
        }
        return false;

    }
};