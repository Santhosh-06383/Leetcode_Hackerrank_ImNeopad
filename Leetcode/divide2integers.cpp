#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the only overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Use long long to safely handle the absolute values
        long long long_dividend = std::abs((long long)dividend);
        long long long_divisor = std::abs((long long)divisor);
        long long quotient = 0;

        // Determine sign
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        while (long_dividend >= long_divisor) {
            long long temp = long_divisor;
            long long multiple = 1;
            
            // Double the divisor until it's larger than dividend
            while (long_dividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            long_dividend -= temp;
            quotient += multiple;
        }

        return (int)(sign * quotient);
    }
};
