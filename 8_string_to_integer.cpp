/*
 Author: ZILI WANG
 Date: 18th Dec 2015
 */

class Solution {
public:
    int myAtoi(string str)
    {
        // empty str
        if (str.empty()) return 0;

        string updated_str = "";
        string sign_str = "";
        string num_str = "";
        bool find_non_space = false;
        bool positive = true;
        long long mul = 1LL;
        long long output = 0LL;

        // remove the spaces in front
        for (size_t i = 0; i < str.size(); ++ i)
        {
            char c = str[i];
            if (c == ' ' && !find_non_space)
                continue;
            else
                find_non_space = true;

            updated_str += c;
        }
        // cout << updated_str << endl;

        if (updated_str.size() == 1) // size = 1
        {
            // not number
            if (updated_str[0] < 48 || updated_str[0] > 57)
                return 0;
            else
                return updated_str[0] - 48;
        }
        else // size > 1
        {
            // deal with the sign first
            for (size_t i = 0; i < updated_str.size(); ++ i)
            {
                char c = updated_str[i];
                if (c == '+' || c == '-')
                    sign_str += c;
                else
                    break;
            }

            if (sign_str.size() == 0)
                positive = true;
            else if (sign_str.size() == 1)
            {
                if (sign_str[0] == '+')
                    positive = true;
                else
                    positive = false;
            }
            else
                return 0;

            // now, the sign is determined
            for (size_t i = sign_str.size(); i < updated_str.size(); ++ i)
            {
                char c = updated_str[i];
                if (c >= 48 && c <= 57)
                    num_str += c;
                else
                    break;
            }

            // convert the num_str to int
            for (int i = (int)num_str.size() - 1; i >= 0; -- i)
            {
                output += (num_str[i] - 48) * mul;
                mul *= 10;

                // check overflow:
                if (output > 2147483647 || output < 0)
                {
                    if (positive)
                        return 2147483647;
                    else
                        return -2147483648;
                }
            }
        }

        if (!positive)
            output *= -1;
        return static_cast<int>(output);
    }
};
