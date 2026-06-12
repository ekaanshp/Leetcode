class Solution {
    std::vector<string> result;
    string digits;
    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void backtrack(string path, int index){
        if(index == digits.size()){
            result.push_back(path);
        }

        for(char letter : phone[digits[index]]){
            backtrack(path + letter, index + 1);
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        backtrack("", 0);
        return result;
    }
};