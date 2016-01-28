/*
 Author: ZILI WANG
 Date: 20th Jan 2016
 */


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // bad solution since O(N square) time complexity
        /*for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;*/

        if (nums.empty())
            return false;

        // using sort() method under Algorithm.h to down the complexity and make the program run faster, the logic is the same as previous one
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};
