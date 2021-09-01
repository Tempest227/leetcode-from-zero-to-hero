class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int max = 0;
        HashMap<Character,Integer> map = new HashMap<Character,Integer>();

        for (int i = 0; i < s.length(); i++)
        {
            if (map.containsKey(s.charAt(i)))
            {
                left = left > map.get(s.charAt(i)) ? left : map.get(s.charAt(i)) + 1;
            }

            map.put(s.charAt(i), i);
            max = max > (i - left + 1) ? max : (i - left + 1);
        }
        return max;
    }
}