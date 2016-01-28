/*
 Author: ZILI WANG
 Date: 15th Dec 2015
 */

class Solution {
public:
    string longestPalindrome(string s) {
        vector<char> l;
        vector<int> count;
        l.push_back('#');
        count.push_back(0);
        for (size_t i = 0; i < s.size(); ++ i)
        {
            l.push_back(s[i]);
            l.push_back('#');
            count.push_back(0);
            count.push_back(0);
        }

        for (size_t i = 0; i < l.size(); ++ i)
        {
            count[i] = 0;

            // leftmost element
            // rightmost element
            if (i == 0 || i == l.size() - 1)
                continue;

            // check left and right
            int l_idx = static_cast<int>(i);
            int r_idx = static_cast<int>(i);
            while (l_idx >= 1 && r_idx <= l.size() - 2)
            {
                if (l[l_idx] == l[r_idx])
                {
                    if (l_idx == r_idx && l[i] != '#')
                        ++ count[i];
                    else if (l[l_idx] != '#')
                        count[i] += 2;

                    -- l_idx;
                    ++ r_idx;
                }
                else
                    break;
            }
        }

        // find the target
        int max_idx = 0;
        int max_val = 0;
        for (size_t i = 0; i < count.size(); ++ i)
        {
            if (count[i] > max_val)
            {
                max_val = count[i];
                max_idx = i;
            }
        }

        int start_idx = max_idx - max_val + 1;
        int end_idx = max_idx + max_val - 1;

        string output = "";
        for (size_t i = start_idx; i <= end_idx; ++ i)
        {
            if (l[i] != '#')
                output += l[i];
        }

        return output;
    }
};
