#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() < 1) return "";
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindrome (center is s[i])
            int len1 = expandAroundCenter(s, i, i);
            // Case 2: Even length palindrome (center is between s[i] and s[i+1])
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = std::max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                // Calculate the start index based on the center i and length len
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // The length of the palindrome is (right - 1) - (left + 1) + 1
        return right - left - 1;
    }
};
