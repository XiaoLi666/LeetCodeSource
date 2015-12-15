/*
 Author: ZILI WANG
 Date: 16th Dec 2015
 Remarks: Need to check the overflow of the reversed number
 */

class Solution {
public:
    int reverse(int x)
    {
        int neg = 1;
        if (x < 0)
        {
            x *= -1;
            neg = -1;
        }

        vector<int> list;
        while (x > 0)
        {
            int c = x%10;
            list.push_back(c);
            x = x/10;
        }

        long long output = 0;
        long long multi = 1;
        for (int i = list.size() - 1; i >= 0; -- i)
        {
            long long adder = (long long)(list[i]) * multi;
            output = output + adder;
            multi *= 10;

            if (output != (int)output)
                return 0;
        }

        return output * neg;
    }
};
