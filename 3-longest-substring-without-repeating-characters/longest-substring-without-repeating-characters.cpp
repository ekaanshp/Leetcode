class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubstring = 0;
        std::unordered_set<char> duplicateChecker;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            while(duplicateChecker.contains(s[i])){
                duplicateChecker.erase(s[start]);
                start++;
            }
            duplicateChecker.insert(s[i]);
            maxSubstring = std::max(i - start + 1, maxSubstring);
        }
        return maxSubstring;
    }
};