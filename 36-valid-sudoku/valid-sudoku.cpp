class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<int> rows[9];
        std::unordered_set<int> cols[9];
        std::unordered_set<int> boxes[3][3];

        for(size_t i = 0; i < board.size(); i++){
            for(size_t j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }

                if(rows[i].count(board[i][j])){
                    return false;
                }
                if(cols[j].count(board[i][j])){
                    return false;
                }
                if(boxes[i / 3][j / 3].count(board[i][j])){
                    return false;
                }

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxes[i / 3][j / 3].insert(board[i][j]);
            }
        }
        return true;
    }
};