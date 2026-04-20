#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        int n = colors.size();
        int max_dist = 0;

        // Case 1: Compare the first house (index 0) with houses from the end
        for (int i = n - 1; i > 0; --i) {
            if (colors[i] != colors[0]) {
                max_dist = std::max(max_dist, i);
                break;
            }
        }

        // Case 2: Compare the last house (index n-1) with houses from the start
        for (int i = 0; i < n - 1; ++i) {
            if (colors[i] != colors[n - 1]) {
                max_dist = std::max(max_dist, (n - 1) - i);
                break;
            }
        }

        return max_dist;
    }
};
