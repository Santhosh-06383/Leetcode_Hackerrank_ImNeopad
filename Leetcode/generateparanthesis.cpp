#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        // Base case: if the string length reaches 2 * n, it's complete
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // Add an opening parenthesis if we still have some left to use
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // Add a closing parenthesis if it matches an existing open one
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};
