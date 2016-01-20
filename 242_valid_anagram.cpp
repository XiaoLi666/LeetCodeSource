/**
 * Author: ZILI WANG
 * Date: 20th Jan 2016
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        return false;
    }
};
