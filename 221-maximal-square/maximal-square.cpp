class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int max_side = 0;
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min({dp[i - 1][j],
                                        dp[i][j - 1],
                                        dp[i - 1][j - 1]});
                    
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        
        return max_side * max_side;
    }
};