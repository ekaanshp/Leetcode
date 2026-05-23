class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        std::vector<int> stack;
        stack.push_back(-1);

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stack.push_back(i);
            }
            else{
                stack.pop_back();
                if(stack.empty()){
                    stack.push_back(i);
                }
                else{
                    longest = std::max(longest, i - stack.back());
                }
            }
        }
        return longest;
    }
};