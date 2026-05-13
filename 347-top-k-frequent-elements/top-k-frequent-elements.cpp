class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counter;
        std::vector<std::vector<int>> frequency;
        frequency.resize(nums.size() + 1);

        for(size_t i = 0; i < nums.size(); i++){
            counter[nums[i]]++;
        }
        for(auto const& [value, count] : counter){
            frequency[count].push_back(value);
        }

        std::vector<int> result;
        for(int i = frequency.size() - 1; i >= 0; i--){
            for(int j = 0; j < frequency[i].size(); j++){
                result.push_back(frequency[i][j]);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};