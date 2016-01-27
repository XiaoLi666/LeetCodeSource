/*
 * Author: Zili Wang
 * Date: 27th Jan 2016
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> singleWords;
        
        sort(nums.begin(), nums.end());
        
        for (size_t i = 1; i < nums.size();) {
            if (nums[i] == nums[i-1])
                i += 2;
            else {
                singleWords.push_back(nums[i-1]);
                i += 1;
            }
        }
        
        if (singleWords.size() < 2) {
            singleWords.push_back(nums[nums.size()-1]);
        }
        
        return singleWords;
    }
};
