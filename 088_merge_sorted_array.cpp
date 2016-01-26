/*
 * Author: Zili Wang
 * Date: 26th Jan 2016
 * Remarks: It could not pass the compile by leetcode online (To Find the Problems)
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (size_t i = 0; i < nums2.size(); ++i) {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
    }
};
