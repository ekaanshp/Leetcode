class Solution {
    int n;
    std::vector<std::vector<string>> result;
    std::vector<bool> column;
    std::vector<bool> pos_diag;
    std::vector<bool> neg_diag;
    
    std::vector<std::string> board;

    void backtrack(int r) {
        if (r == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (column[c] || pos_diag[r + c] || neg_diag[r - c + n]) {
                continue;
            }

            column[c] = true;
            pos_diag[r + c] = true;
            neg_diag[r - c + n] = true;
            board[r][c] = 'Q';

            backtrack(r + 1);

            column[c] = false;
            pos_diag[r + c] = false;
            neg_diag[r - c + n] = false;
            board[r][c] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        column.resize(n, false);
        pos_diag.resize(2 * n, false);
        neg_diag.resize(2 * n, false);
        board = std::vector<std::string>(n, std::string(n, '.'));
        backtrack(0);
        return result;
    }
};