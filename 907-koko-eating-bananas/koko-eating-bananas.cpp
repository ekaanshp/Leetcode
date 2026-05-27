class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int result = right;
        while(left <= right){
            int k = (left + right) / 2;
            double hours = 0;
            for(int i = 0; i < piles.size(); i++){
                hours += std::ceil((double)piles[i] / k);
            }

            if(hours <= h){
                result = std::min(result, k);
                right = k - 1;
            }
            else{
                left = k + 1;
            }
        }
        return result;
    }
};