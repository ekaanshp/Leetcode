class Solution {
    int n;
    std::vector<std::vector<string>> result;
    std::unordered_set<int> column;
    std::unordered_set<int> pos_diag;
    std::unordered_set<int> neg_diag;
    std::vector<string> board;

    void backtrack(int r){
        if(r == n){
            result.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            if(column.contains(c) || pos_diag.contains(r + c) || neg_diag.contains(r - c)){
                continue;
            }
            column.insert(c);
            pos_diag.insert(r + c);
            neg_diag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1);

            column.erase(c);
            pos_diag.erase(r + c);
            neg_diag.erase(r - c);
            board[r][c] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = std::vector<std::string>(n, std::string(n, '.'));
        backtrack(0);
        return result;
    }
};