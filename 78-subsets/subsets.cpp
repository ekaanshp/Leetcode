class Solution {
    std::vector<std::vector<int>> result;
    std::vector<int> path;

    void dfs(int index, vector<int>& path, vector<int>& nums){
        if(index == nums.size()){
            result.push_back(path);
            return;
        }

        path.push_back(nums[index]);
        dfs(index + 1, path, nums);

        path.pop_back();
        dfs(index + 1, path, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, path, nums);
        return result;
    }
};