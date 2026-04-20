#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board, 0, 0);
    }

private:
    bool solve(std::vector<std::vector<char>>& board, int row, int col) {
        // Move to next row if we reach end of columns
        if (col == 9) return solve(board, row + 1, 0);
        // Base case: if we reach row 9, the puzzle is solved
        if (row == 9) return true;
        
        // Skip already filled cells
        if (board[row][col] != '.') return solve(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                
                // Recurse to the next cell
                if (solve(board, row, col + 1)) return true;
                
                // Backtrack
                board[row][col] = '.';
            }
        }
        return false;
    }

    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char c) {
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        
        for (int i = 0; i < 9; i++) {
            // Check row, column, and 3x3 box in a single loop
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[startRow + i / 3][startCol + i % 3] == c) return false;
        }
        return true;
    }
};
