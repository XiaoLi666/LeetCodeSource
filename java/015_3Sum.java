/*
 * Author: Zili Wang
 * Date: 10th Feb 2016
 */

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int lIdx = i + 1;
            int rIdx = nums.length - 1;
            
            while (lIdx < rIdx) {
                int v = nums[i] + nums[lIdx] + nums[rIdx];
                if (v == 0) {
                    List<Integer> newList = new ArrayList<Integer>();
                    newList.add(new Integer(nums[i]));
                    newList.add(new Integer(nums[lIdx]));
                    newList.add(new Integer(nums[rIdx]));
                    result.add(newList);
                    while (lIdx < rIdx && nums[lIdx] == nums[lIdx + 1])
                        ++lIdx;
                    while (lIdx < rIdx && nums[rIdx] == nums[rIdx - 1])
                        --rIdx;
                    ++lIdx;
                    --rIdx;
                }
                else if (v > 0) {
                    --rIdx;
                }
                else if (v < 0) {
                    ++lIdx;
                }
            }
        }
        return result;
    }
}
