class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> result;

        for(int i = 0; i < strs.size(); i++){
            std::string count(26, 0); 
            for(int j = 0; j < strs[i].size(); j++){
                count[strs[i][j] - 'a']++;
            }

            result[count].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> returnOutput;
        for(auto& pair : result){
            returnOutput.push_back(std::move(pair.second));
        }
        return returnOutput;
    }
};