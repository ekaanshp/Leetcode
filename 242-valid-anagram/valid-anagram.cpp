class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        std::unordered_map<char, int> stringS;
        std::unordered_map<char, int> stringT;

        for(size_t i = 0; i < s.length(); i++){
            stringS[s[i]]++;
            stringT[t[i]]++;
        }

        for(size_t i = 0; i < s.length(); i++){
            if(stringS[s[i]] != stringT[s[i]]){
                return false;
            }
        }
        return true;
    }
};