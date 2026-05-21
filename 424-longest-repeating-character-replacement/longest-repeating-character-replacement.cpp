class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> characterCounter;
        int result = 0;
        int left = 0;
        int maxFrequency = 0;

        for(int i = 0; i < s.size(); i++){
            characterCounter[s[i]]++;
            maxFrequency = std::max(maxFrequency, characterCounter[s[i]]);

            while((i - left + 1) - maxFrequency > k){
                characterCounter[s[left]]--;
                left++;
            }
            result = std::max(result, i - left + 1);
        }
        return result;
    }
};