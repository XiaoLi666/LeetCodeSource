/*
 Author: ZILI WANG
 Date: 10th Jan 2016
 */

class Solution {
public:
    int addDigits(int num)
    {
        int sum = 0;
        int result = num;
        while (result >= 10)
        {
            while (num > 0)
            {
                sum += num % 10;
                num = num / 10;
            }
            result = sum;
            num = sum;
            sum = 0;
        }
        return result;
    }
};
