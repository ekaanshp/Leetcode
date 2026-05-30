class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::vector<int> result;
        result.resize(2);

        for(int i = 0; i < nums.size(); i++){
            int value = abs(nums[i]);
            if(nums[value - 1] < 0){
                result[0] = value;
            }
            else{
                nums[value - 1] *= -1;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                result[1] = i + 1;
                break;
            }
        }
        return result;
    }
};