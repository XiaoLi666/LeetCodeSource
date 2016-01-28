/*
 Author: ZILI WANG
 Date: 10th Jan 2016
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int end_index = nums.size()-1;

        for (size_t i = 0; i < nums.size();) {
            if (i >= end_index) {
                break;
            }

            if (nums[i] == 0) {
                for (unsigned int j = i; j < end_index; ++j) {
                    nums[j] = nums[j+1];
                }
                nums[end_index] = 0;
                --end_index;
            }
            else
                ++i;
        }
    }
};
