/*
 * Author: Zili Wang
 * Date: 26th Jan 2016
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        
        vector<int> updated_list;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                updated_list.push_back(nums[i]);
            }
        }
        nums = updated_list;
        return updated_list.size();
    }
};
