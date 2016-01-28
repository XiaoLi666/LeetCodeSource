/*
 Author: ZILI WANG
 Date: 20th Dec 2015
 */

class Solution {
public:
    int titleToNumber(string s) {
        static const unsigned int RANGE = 26;
        static const int A_ASCII = 64;
        size_t size = s.size();
        int mul = 1;
        int title = 0;

        for (int i = size-1; i >= 0; --i) {
            int del = mul;
            title = title + (s[i] - A_ASCII) * del;
            mul*=RANGE;
        }

        return title;
    }
};
