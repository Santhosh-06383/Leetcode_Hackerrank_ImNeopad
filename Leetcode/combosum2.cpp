#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        std::sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(result, path, candidates, target, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& path, 
                   std::vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Pruning: if current number is greater than target, stop
            if (candidates[i] > target) break;

            // Skip duplicate numbers to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            // Move to i + 1 because each number can only be used once
            backtrack(result, path, candidates, target - candidates[i], i + 1);
            path.pop_back(); // Backtrack
        }
    }
};
