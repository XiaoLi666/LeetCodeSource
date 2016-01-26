/*
 * Author: Zili Wang
 * Date: 26th Jan 2016
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> result;
        int carry = 0;
        digits[digits.size()-1] += 1;
        
        for (int i = digits.size()-1; i >= 0; --i) {
            int value = digits[i];
            value += carry;
            if (value >= 10) {
                carry = value/10;
                value = value%10;
            }
            else
                carry = 0;
            
            digits[i] = value;
        }
        
        if (carry == 1)
            result.push_back(1);
        
        for (size_t i = 0; i < digits.size(); ++i) {
            result.push_back(digits[i]);
        }
        
        return result;
    }
};
