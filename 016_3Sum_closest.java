/*
 * Author: Zili Wang
 * Date: 10th Feb 2016
 */

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int closest = -1;
        int result = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i + 1;
            int r = nums.length - 1;
            
            while (l < r) {
                int v = nums[i]+nums[l]+nums[r];
                
                int d;
                
                if (v > target) {
                    --r;
                    d = v-target;
                }
                else if (v < target) {
                    ++l;
                    d = target-v;
                }
                else {
                    return v;
                }
                
                if (closest < 0 || d < closest) {
                	closest = d;
                	result = v;
                }
            }
        }
        
        return result;
    }
}
