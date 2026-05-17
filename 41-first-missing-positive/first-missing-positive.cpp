class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                nums[i] = 0;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            int value = std::abs(nums[i]);
            if((value >= 1) && (value <= nums.size())){
                if(nums[value - 1] > 0){
                    nums[value - 1] *= -1;
                }
                else if(nums[value - 1] == 0){
                    nums[value - 1] = -1 * (nums.size() + 1); 
                }
            }
        }

        for(int i = 1; i < nums.size() + 1; i++){
            if(nums[i - 1] >= 0){
                return i;
            }
        }
        return nums.size() + 1;
    }
};