class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int midpoint = (left + right) / 2;
            if(nums[midpoint] == target){
                return midpoint;
            }
            else if(target < nums[midpoint]){
                right = midpoint - 1;
            }
            else{
                left = midpoint + 1;
            }
        }
        return -1;
    }
};