class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max = 0;
        while(l < r){
            int currentWidth = r - l;
            int currentHeight = std::min(height[l], height[r]);
            int currentArea = currentWidth * currentHeight;
            max = std::max(max, currentArea);

            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max;
    }
};