#include <string>
#include <iostream>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty()){
            return 0;
        }

        int n = s.size();
        int next1 = 1;
        int next2 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int current = 0;

            if (s[i] != '0') {
                current += next1;
            }

            if (i + 1 < n) {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                    current += (i + 2 < n) ? next2 : 1;
                }
            }
            next2 = next1;
            next1 = current;
        }
        return next1;
    }
};