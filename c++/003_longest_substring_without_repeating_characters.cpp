/*
 Author: ZILI WANG
 Date: 11th Dec 2015
 Remarks: passed performance test
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
        bool used[256];
        memset(used, false, sizeof(used));

        for (unsigned int i = 0; i < s.size(); ++ i) {
            current_length = 1;
            memset(used, false, sizeof(used));
            used[s[i]] = true;

            for (unsigned int j = i + 1; j < s.size(); ++ j) {
                duplicated = false;

                if (used[s[j]] == true) {
                    duplicated = true;
                }

                if (!duplicated) {
                    used[s[j]] = true;
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
