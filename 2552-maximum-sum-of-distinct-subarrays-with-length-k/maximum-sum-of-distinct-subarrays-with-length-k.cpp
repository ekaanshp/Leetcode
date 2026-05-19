class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0;
        std::unordered_map<int, int> duplicateCounter;
        int start = 0;
        long long runningTotal = 0;

        for(int i = 0; i < nums.size(); i++){
            duplicateCounter[nums[i]]++;
            runningTotal += nums[i];

            if((i - start + 1) != k){
                continue;
            }
            if(duplicateCounter.size() == k){
                result = std::max(result, runningTotal);
            }

            duplicateCounter[nums[start]]--;
            if(duplicateCounter[nums[start]] == 0){
                duplicateCounter.erase(nums[start]);
            }
            runningTotal -= nums[start];
            start++;
        }
        return result;
    }
};