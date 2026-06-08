class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto target = nums.begin() + (nums.size() - k);
        std::nth_element(nums.begin(), target, nums.end());
        return *target;
    }
};