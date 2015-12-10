class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(0);
        int value_1 = nums[result[0]];
        int value_2;
        while (1) {
            for (size_t i = result[0] + 1; i < nums.size(); ++ i) {
                value_2 = nums[i];
                if (value_1 + value_2 == target) {
                    result.push_back(i);
                    ++ result[0];
                    ++ result[1];
                    return result;
                }
            }
            ++ result[0];
            value_1 = nums[result[0]];
        }
    }
};
