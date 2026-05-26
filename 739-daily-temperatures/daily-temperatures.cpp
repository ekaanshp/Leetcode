class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::vector<int> stack;
        for(int i = 0; i < temperatures.size(); i++){
            while(!stack.empty() && temperatures[i] > temperatures[stack.back()]){
                result[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return result;
    }
};