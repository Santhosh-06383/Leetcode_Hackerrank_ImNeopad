#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int totalLen = wordCount * wordLen;

        if (n < totalLen) return result;

        std::unordered_map<std::string, int> counts;
        for (const std::string& word : words) {
            counts[word]++;
        }

        // We only need to start from 0 to wordLen - 1
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            std::unordered_map<std::string, int> window;
            int count = 0;

            while (right + wordLen <= n) {
                std::string word = s.substr(right, wordLen);
                right += wordLen;

                if (counts.count(word)) {
                    window[word]++;
                    count++;
                    
                    // If we have more of 'word' than allowed, slide 'left'
                    while (window[word] > counts[word]) {
                        std::string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Success: all words matched
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Not a valid word, reset window
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
