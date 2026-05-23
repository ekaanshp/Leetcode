class Solution {
public:
    string decodeString(string s) {
        std::string storage = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                storage.push_back(s[i]);
            }
            else {
                std::string substring = "";
                while (storage.back() != '[') {
                    substring = storage.back() + substring;
                    storage.pop_back();
                }
                storage.pop_back();

                std::string digit = "";
                while (!storage.empty() && std::isdigit(storage.back())) {
                    digit = storage.back() + digit;
                    storage.pop_back();
                }
                
                int intDigit = std::stoi(digit);
                for (int j = 0; j < intDigit; j++) {
                    storage += substring;
                }
            }
        }
        return storage;
    }
};