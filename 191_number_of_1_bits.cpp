/*
 * Author: Zili Wang
 * Date: 22nd Jan 2016
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int count = 0;
        while (n > 0) {
            if (n % 2 == 1) // check whether the right most bit is 1 or not 
                ++ count;
            n /= 2; // n >> 1 is not working here
        }
        return count;
    }
};
