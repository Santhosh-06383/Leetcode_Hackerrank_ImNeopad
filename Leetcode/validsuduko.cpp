#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Use boolean arrays for O(1) lookups
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1'; // Convert '1'-'9' to index 0-8
                int box_idx = (r / 3) * 3 + (c / 3);

                // Check for duplicates
                if (rows[r][val] || cols[c][val] || boxes[box_idx][val]) {
                    return false;
                }

                // Mark digit as seen
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[box_idx][val] = true;
            }
        }
        return true;
    }
};
