class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        std::function<void(int, int)> dfs = [&](int r, int c){
            if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O'){
                return;
            }
            board[r][c] = 'S';
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O' && (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)){
                    dfs(i, j);
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};