class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }

        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            while(i < j && !std::isalnum(s[i])){
                i++;
            }
            while(j > i && !std::isalnum(s[j])){
                j--;
            }
            if(std::tolower(s[i]) != std::tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};