class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int result = 0;

        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = std::max(leftMax, height[left]);
                result += leftMax - height[left];
            }
            else{
                right--;
                rightMax = std::max(rightMax, height[right]);
                result += rightMax - height[right];
            }
        }
        return result;
    }
};