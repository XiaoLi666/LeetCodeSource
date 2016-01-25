/*
 * Author: Zili Wang
 * Date: 25th Jan 2016
 */

class Solution {
public:
    int climbStairs(int n) {
        /* Solution 1:
        static int count = 0;
        if (n < 0) {
            return count;
        }
        if (n == 0) {
            ++ count;
            return count;
        }
        
        climbStairs(n-1);
        climbStairs(n-2);
        return count;*/
        
        /* Solution 2:
        if (n < 0) return 0;
        if (n == 0) return 1;
        return climbStairs(n-1) + climbStairs(n-2);*/
        
        /* Solution 3: using loop instead of recursive function
        unsigned int count = 0;
        vector<int> s;
        s.push_back(n);
        while (!s.empty()) {
            int v = s.back();
            s.pop_back();
            
            int sibling_1 = v-1;
            int sibling_2 = v-2;
            
            if (sibling_1 > 0) {
                s.push_back(sibling_1);
            }
            else if (sibling_1 == 0) {
                ++ count;
            }
            
            if (sibling_2 > 0) {
                s.push_back(sibling_2);
            }
            else if (sibling_2 == 0) {
                ++ count;
            }
        }
        return count;*/
        
        // Solution 4: dynamic programming
        vector<int> res(n+1);
        res[0] = 1;
        res[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        
        return res[n];
    }
};
