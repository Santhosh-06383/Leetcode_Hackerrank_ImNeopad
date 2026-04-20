#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        // Sorting helps in pruning the recursion tree
        std::sort(candidates.begin(), candidates.end());
        backtrack(result, current, candidates, target, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& current, 
                   std::vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Pruning: no need to check further if the number exceeds remaining target
            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            // Re-use the same index 'i' to allow unlimited usage of the same number
            backtrack(res, current, candidates, target - candidates[i], i);
            current.pop_back(); // Backtrack
        }
    }
};
