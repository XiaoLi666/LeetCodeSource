/*
 * Author: Zili Wang
 * Date: 10th Feb 2016
 */

public class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        
        String ans = "";
        ArrayList<ArrayList<Character>> m = new ArrayList<ArrayList<Character>>();
        for (int i = 0; i < numRows; ++ i) {
            ArrayList<Character> newList = new ArrayList<Character>();
            m.add(newList);
        }
        
        int i = 0;
        while (i < s.length()) {
            // from top to bottom
            for (int j = 0; j < numRows; ++j) {
                if (i >= s.length()) break;
                Character c = new Character(s.charAt(i));
                m.get(j).add(c);
                ++i;
            }
            
            // from bottom to top
            for (int j = numRows - 2; j > 0; --j) {
                if (i >= s.length()) break;
                Character c = new Character(s.charAt(i));
                m.get(j).add(c);
                ++i;
            }
        }
        
        for (i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m.get(i).size(); ++j) {
                ans += m.get(i).get(j).toString();
            }
        }
        
        return ans;
    }
}
