/*
 Author: ZILI WANG
 Date: 20th Dec 2015
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        if (nums.size() == 1)
            return nums[0];

        sort(nums.begin(), nums.end());
        unsigned int count = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1])
                ++count;
            else
                count = 0;

            if (count >= nums.size()/2) {
                return nums[i];
            }
        }
    }
};
