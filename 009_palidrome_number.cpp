/*
 Author: ZILI WANG
 Date: 18th Dec 2015
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x / 10 == 0) return true;

        // find the length of the integer
        int length = 0;
        int v = x;
        while (v > 0) {
            v = v / 10;
            ++ length;
        }

        int c = 1;
        while (1) {
            c *= 10;
            -- length;
            if (length == 1)
                break;
        }

        while (x > 0) {
            int a = x % 10;
            int b = x / c;
            if (a != b)
                return false;

            x = x % c;
            x /= 10;
            c /= 100;
        }

        return true;
    }
};
