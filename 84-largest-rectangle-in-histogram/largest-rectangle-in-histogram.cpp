class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        std::vector<int> stack;

        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!stack.empty() && heights[stack.back()] > heights[i]){
                int index = stack.back();
                stack.pop_back();
                int currentArea = heights[index] * (i - index);
                maxArea = std::max(maxArea, currentArea);
                start = index;
            }

            heights[start] = heights[i];
            stack.push_back(start);
        }
        
        
        while(!stack.empty()){
            int index = stack.back();
            stack.pop_back();
            int currentArea = heights[index] * (heights.size() - index);
            maxArea = std::max(maxArea, currentArea);
        }
        return maxArea;
    }
};