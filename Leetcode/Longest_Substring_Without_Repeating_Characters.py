class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        int last[256];
        memset(last, -1, sizeof(last)); 
        
        int maxLen = 0;
        int start = 0;  
        
        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char c = s[i];
            
            
            if (last[c] >= start) {
                start = last[c] + 1;
            }
            
            last[c] = i;  
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};
