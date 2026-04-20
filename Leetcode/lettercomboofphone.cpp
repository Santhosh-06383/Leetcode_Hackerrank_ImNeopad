#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};
        
        std::vector<std::string> result;
        std::string current;
        // Mapping index matches the digit (0 and 1 are empty)
        std::vector<std::string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        backtrack(result, digits, mapping, current, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, const std::string& digits, 
                   const std::vector<std::string>& mapping, std::string& current, int index) {
        // Base case: we've used all digits
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        std::string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);           // Choose
            backtrack(result, digits, mapping, current, index + 1); // Explore
            current.pop_back();            // Un-choose (backtrack)
        }
    }
};
