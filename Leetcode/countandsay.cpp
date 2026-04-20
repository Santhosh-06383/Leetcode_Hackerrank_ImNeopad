#include <string>
#include <vector>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) return "1";
        
        std::string current = "1";
        
        // Generate sequence up to n
        for (int i = 2; i <= n; ++i) {
            std::string next = "";
            int len = current.length();
            
            for (int j = 0; j < len; ++j) {
                int count = 1;
                // Count consecutive identical characters
                while (j + 1 < len && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }
                // Append count then character
                next += std::to_string(count) + current[j];
            }
            current = next;
        }
        
        return current;
    }
};
