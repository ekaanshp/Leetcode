class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> tails;

        for(int num : nums){
            auto it = std::lower_bound(tails.begin(), tails.end(), num);

            if(it == tails.end()){
                tails.push_back(num);
            }
            else{
                *it = num;
            }
        }
        return tails.size();
    }
};