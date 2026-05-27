class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = nums[0];
        while(left <= right){
            if(nums[left] < nums[right]){
                result = std::min(result, nums[left]);
                break;
            }
            int midpoint = (left + right) / 2;
            result = std::min(result, nums[midpoint]);
            if(nums[midpoint] >= nums[left]){
                left = midpoint + 1;
            }
            else{
                right = midpoint - 1;
            }
        }
        return result;
    }
};