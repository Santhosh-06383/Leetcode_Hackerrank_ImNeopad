class Solution {
public:
    bool isPalindrome(int x) {
        // Negatives and numbers ending in 0 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // x == reversedHalf: even digits (1221 -> x=12, rev=12)
        // x == reversedHalf / 10: odd digits (121 -> x=1, rev=12)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
