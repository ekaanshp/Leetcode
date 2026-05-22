class Solution {
public:
    bool isValid(string s) {
        std::stack<char> checker;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                checker.push(s[i]);
            }

            if(s[i] == ')'){
                if(checker.empty() || checker.top() != '('){
                    return false;
                }
                checker.pop();
            }
            else if(s[i] == '}'){
                if(checker.empty() || checker.top() != '{'){
                    return false;
                }
                checker.pop();
            }
            else if(checker.empty() || s[i] == ']'){
                if(checker.empty() || checker.top() != '['){
                    return false;
                }
                checker.pop();
            }
        }
        return checker.empty();
    }
};