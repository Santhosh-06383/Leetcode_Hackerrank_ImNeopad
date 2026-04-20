#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate current area
            int current_height = std::min(height[left], height[right]);
            int current_width = right - left;
            int current_area = current_height * current_width;
            
            // Update max_area if current is larger
            max_area = std::max(max_area, current_area);
            
            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};
