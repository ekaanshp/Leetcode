class Solution {
    std::vector<std::vector<int>> result;
    int target;

    void backtrack(int i, int total, std::vector<int>& current, const std::vector<int>& candidates){
        if(total == target){
            result.push_back(current);
            return;
        }
        if(i >= candidates.size() || total > target){
            return;
        }

        current.push_back(candidates[i]);
        backtrack(i, total + candidates[i], current, candidates);

        current.pop_back();
        backtrack(i + 1, total, current, candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        std::vector<int> current;
        backtrack(0, 0, current, candidates);
        return result;
    }
};