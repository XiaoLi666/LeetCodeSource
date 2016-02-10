/*
 * Author: Zili Wang
 * Date: 20th Feb 2016
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // faster solution
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size()-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
                
            int leftIdx = i+1;
            int rightIdx = nums.size()-1;
            while (leftIdx < rightIdx) {
                int v = nums[i] + nums[leftIdx] + nums[rightIdx];
                if (v < 0) ++leftIdx;
                else if (v > 0) --rightIdx;
                else {
                    vector<int> s;
                    s.push_back(nums[i]);
                    s.push_back(nums[leftIdx]);
                    s.push_back(nums[rightIdx]);
                    result.push_back(s);
                    while (nums[leftIdx] == nums[leftIdx + 1])
                        ++leftIdx;
                    while (nums[rightIdx] == nums[rightIdx - 1])
                        --rightIdx;
                    ++leftIdx;
                    --rightIdx;
                }
            }
        }
        
        return result;
        
        // slow solution
        /*sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (size_t j = i + 1; j < nums.size(); ++j) {
                for (size_t k = j + 1; k < nums.size(); ++k) {
                    int v = nums[i] + nums[j] + nums[k];
                    if (v == 0) {
                        vector<int> s;
                        s.push_back(nums[i]);
                        s.push_back(nums[j]);
                        s.push_back(nums[k]);
                        result.push_back(s);
                    }
                }
            }
        }
        return result;*/
    }
};
