class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> bottomUp(s.size(), false);
        bottomUp[s.size()] = true;

        for(int i = s.size() - 1; i >= 0; i--){
            for(const std::string& w : wordDict){
                if(i + w.size() <= s.size() && s.substr(i, w.size()) == w){
                    bottomUp[i] = bottomUp[i + w.size()];
                }

                if(bottomUp[i]){
                    break;
                }
            }
        }
        return bottomUp[0];
    }
};