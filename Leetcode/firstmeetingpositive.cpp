#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // While the current number is in range and not at its correct index
            // and the target index doesn't already have the correct number
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find the first index that doesn't match its value
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If 1 to n are all present
        return n + 1;
    }
};
