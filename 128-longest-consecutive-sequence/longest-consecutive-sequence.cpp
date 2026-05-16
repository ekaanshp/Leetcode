class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numberSet(nums.begin(), nums.end());
        int longestSequence = 0;

        for(int num : numberSet){
            if(!numberSet.count(num - 1)){
                int nextNum = num;
                while(numberSet.count(nextNum)){
                    nextNum++;
                }
                int currentLength = nextNum - num;
                longestSequence = std::max(longestSequence, currentLength);
            }
        }
        return longestSequence;
    }
};