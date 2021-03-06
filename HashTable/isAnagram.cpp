class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a'] -= 1;
        }
        for (auto e : record)
        {
            if (e != 0)
            {
                return false;
            }
        }
        return true;
    }
};