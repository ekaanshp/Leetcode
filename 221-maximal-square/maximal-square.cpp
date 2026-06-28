class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, -1));

        std::function<int(int, int)> helper = [&](int r, int c){
            if(r >= rows || c >= cols){
                return 0;
            }

            if(memo[r][c] == -1){
                int down = helper(r + 1, c);
                int right = helper(r, c + 1);
                int downRight = helper(r + 1, c + 1);
                memo[r][c] = 0;

                if(matrix[r][c] == '1'){
                    memo[r][c] = 1 + std::min(down, std::min(right, downRight));
                }
            }
            return memo[r][c];
        };

        helper(0, 0);
        int max = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(memo[i][j] > max){
                    max = memo[i][j];
                }
            }
        }
        return max * max;
    }
};