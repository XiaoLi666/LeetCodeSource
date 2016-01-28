/*
 Author: ZILI WANG
 Date: 15th Dec 2015
 */

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<vector<char>> matrix;

        for (unsigned int i  = 0; i < numRows; ++ i)
        {
            vector<char> row;
            matrix.push_back(row);
        }

        bool down = true;
        int idx = 0;
        bool finish = false;
        while (1)
        {
            if (finish) break;

            if (down)
            {
                for (unsigned int j = 0; j < numRows; ++ j)
                {
                    if (idx < s.size())
                    {
                        matrix[j].push_back(s[idx]);
                        ++ idx;
                    }
                    else
                    {
                        finish = true;
                        break;
                    }
                }
                down = false;
            }
            else
            {
                matrix[0].push_back(' ');
                matrix[numRows-1].push_back(' ');
                for (unsigned int j = numRows - 2; j > 0; -- j)
                {
                    if (idx < s.size())
                    {
                        matrix[j].push_back(s[idx]);
                        ++ idx;
                    }
                    else
                    {
                        finish = true;
                        break;
                    }
                }
                down = true;
            }
        }

        string output = "";
        for (size_t i = 0; i < matrix.size(); ++ i)
        {
            for (size_t j = 0; j < matrix[i].size(); ++ j)
            {
                if (matrix[i][j] != ' ')
                    output += matrix[i][j];
            }
        }

        return output;
    }
};
