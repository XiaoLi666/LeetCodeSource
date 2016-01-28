class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double mid = 0.0;
        unsigned int idx1 = 0;
        unsigned int idx2 = 0;
        vector<int> sorted_list;

        if (nums1.empty() && nums2.empty()) {
            return 0.0;
        }
        else if (nums1.empty()) {
            sorted_list = nums2;
        }
        else if (nums2.empty()) {
            sorted_list = nums1;
        }
        else {
            while (1) {
                if (idx1 >= nums1.size() && idx2 >= nums2.size()) {
                    break;
                }

                if (idx1 >= nums1.size() || (nums1[idx1] > nums2[idx2] && idx2 < nums2.size())) {
                    sorted_list.push_back(nums2[idx2]);
                    ++ idx2;
                }
                else if (idx2 >= nums2.size() || (nums1[idx1] < nums2[idx2] && idx1 < nums1.size())) {
                    sorted_list.push_back(nums1[idx1]);
                    ++ idx1;
                }
                else {
                    sorted_list.push_back(nums1[idx1]);
                    ++ idx1;
                }
            }
        }

        if (sorted_list.size() % 2 == 1) {
            mid = static_cast<double>(sorted_list[sorted_list.size()/2]);
        }
        else {
            double n1 = static_cast<double>(sorted_list[(sorted_list.size()-1)/2]);
            double n2 = static_cast<double>(sorted_list[sorted_list.size()/2]);
            mid = (n1 + n2) / 2.0;
        }

        return mid;
    }
};
