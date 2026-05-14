class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result;
        result.resize(nums.size());

        int prefix = 1;
        for(size_t i = 0; i < nums.size(); i++){
            result[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};