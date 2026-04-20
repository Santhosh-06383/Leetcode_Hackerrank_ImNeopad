#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // If only 1 row, or the string fits in one column
        if (numRows == 1 || numRows >= s.length()) return s;

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            // Reverse direction if we hit the top or bottom boundary
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a final result
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
