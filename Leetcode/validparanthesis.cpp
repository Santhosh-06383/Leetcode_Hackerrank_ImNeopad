#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        // Map closing brackets to their corresponding opening brackets
        std::unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (bracketMap.count(c)) {
                // Check if stack is empty or top doesn't match
                if (st.empty() || st.top() != bracketMap[c]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket, push to stack
                st.push(c);
            }
        }

        // String is valid only if stack is empty
        return st.empty();
    }
};
