public class Solution {
    public int lengthOfLongestSubstring(String s) {
        String subStr = "";
        int longestLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++ j) {
                char cc = s.charAt(j);
                if (subStr.indexOf(cc) == -1) {
                    subStr += cc;
                }
                else {
                    break;
                }
            }
            if (subStr.length() > longestLen) {
                longestLen = subStr.length();
            }
            subStr = "";
        }
        return longestLen;
    }
}
