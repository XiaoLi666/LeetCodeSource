/*
 * Author: Zili Wang
 * Date: 25th Jan 2016
 */

class Solution {
public:
    bool isHappy(int n) {
        set<int> results;
        int result = n;
        do {
            int value = result;
            result = 0;
            while (value > 0) {
                int m = value % 10;
                m *= m;
                result += m;
                value /= 10;
            }
            
            if (results.find(result) != results.end()) {
                return false;
            }
            results.insert(result);
            
        } while (result != 1);
        return result == 1;
    }
};
