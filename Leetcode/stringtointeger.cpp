#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, n = s.length();
        int sign = 1;
        int result = 0;

        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') i++;

        // 2. Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Conversion and overflow check
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow/underflow before updating result
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
