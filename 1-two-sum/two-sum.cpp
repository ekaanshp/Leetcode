class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> returnVector;
        std::unordered_map<int, int> differences;

        for(int i = 0; i < nums.size(); i++){
            if(!differences.contains(target - nums[i])){
                differences[nums[i]] = i;
            }
            else{
                returnVector.push_back(differences[target - nums[i]]);
                returnVector.push_back(i);
                break;
            }
        }
        return returnVector;
    }
};