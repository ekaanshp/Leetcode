class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> memo(amount + 1, amount + 1);

        memo[0] = 0;

        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    memo[i] = std::min(memo[i], 1 + memo[i - coins[j]]);
                }
            }
        }

        if(memo[amount] == amount + 1){
            return -1;
        }
        else{
            return memo[amount];
        }
    }
};