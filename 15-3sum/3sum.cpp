class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int threeSum = nums[i] + nums[l] + nums[r];
                if(threeSum > 0){
                    r--;
                }
                else if(threeSum < 0){
                    l++;
                }
                else{
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l] == nums[l - 1] && l < r){
                        l++;
                    }
                }
            }
        }
        return result;
    }
};