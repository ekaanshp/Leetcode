class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> nonDuplicates;
        for(size_t i{0}; i < nums.size(); i++){
            if(nonDuplicates.contains(nums[i])){
                return true;
            }
            else{
                nonDuplicates.insert(nums[i]);
            }
        }
        return false;
    }
};