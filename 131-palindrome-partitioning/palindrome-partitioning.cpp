class Solution {
    std::vector<std::vector<string>> result;
    std::vector<string> part;
    string s;

    void backtracking(int i){
        if(i >= s.size()){
            result.push_back(part);
            return;
        }

        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                part.push_back(s.substr(i, j - i + 1));
                backtracking(j + 1);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        backtracking(0);
        return result;
    }
};