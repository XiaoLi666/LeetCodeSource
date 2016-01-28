/*
 * Author: Zili Wang
 * Date: 25th Jan 2016
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int t = n - 1;
        return (n > 0) && !(t & n);
    }
};
