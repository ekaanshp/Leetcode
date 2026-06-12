class Solution {
    std::vector<string> result;
    string parenthesis = "";
    void backtrack(int openN, int closedN, int n){
        if(openN == closedN && closedN == n){
            result.push_back(parenthesis);
        }

        if(openN < n){
            parenthesis += '(';
            backtrack(openN + 1, closedN, n);
            parenthesis.pop_back(); 
        }

        if(closedN < openN){
            parenthesis += ')';
            backtrack(openN, closedN + 1, n);
            parenthesis.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return result;
    }
};