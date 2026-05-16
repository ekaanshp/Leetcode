class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int currentSum = 0;
        std::unordered_map<int, int> prefixSumCounter;
        prefixSumCounter[0] = 1;

        for(size_t i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            int difference = currentSum - k;
            if(prefixSumCounter.contains(difference)){
                result += prefixSumCounter[difference];
            }
            prefixSumCounter[currentSum]++;
        }
        return result;
    }
};