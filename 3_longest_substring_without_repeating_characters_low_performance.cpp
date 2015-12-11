/*
 Author: ZILI WANG
 Date: 11th Dec 2015
 Remarks: Low performance for very long string
 */
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int current_length = 1;
        int longest_length = current_length;
        int start_index = 0;
        bool duplicated = false;

        for (unsigned int i = 0; i < s.size(); ++ i) {
            current_length = 1;
            for (unsigned int j = i + 1; j < s.size(); ++ j) {
                duplicated = false;
                for (unsigned int k = i; k < j; ++ k) {
                    if (s[k] == s[j]) {
                        duplicated = true;
                        break;
                    }
                }
                if (!duplicated) {
                    ++ current_length;
                    if (current_length > longest_length) {
                        longest_length = current_length;
                        start_index = i;
                    }
                }
                else {
                    break;
                }
            }
        }
        return longest_length;
    }
};
