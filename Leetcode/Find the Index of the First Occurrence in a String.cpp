#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.length();
        int m = needle.length();

        // If needle is longer than haystack, it can't be a match
        if (m > n) return -1;

        // Slide the window across the haystack
        for (int i = 0; i <= n - m; i++) {
            // Check if the substring starting at i matches needle
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};
