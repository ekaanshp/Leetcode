class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> prices(n, std::numeric_limits<int>::max());
        prices[src] = 0;

        std::vector<int> tmp;
        for(int i = 0; i < k + 1; i++){
            tmp = prices;
            for(const auto& flight : flights){
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];

                if(prices[s] == std::numeric_limits<int>::max()){
                    continue;
                }
                if(prices[s] + p < tmp[d]){
                    tmp[d] = prices[s] + p;
                }
            }
            prices = tmp;
        }
        if(prices[dst] == std::numeric_limits<int>::max()){
            return -1;
        }
        return prices[dst];
    }
};