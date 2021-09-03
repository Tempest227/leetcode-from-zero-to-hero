class Solution {
public:
    void getNext(int* next, const string& s)
    {
        int j = 0;
        next[0] = 0;

        for (int i = 1; i < s.size(); i++)
        {
            while(j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
        {
            return true;
        }
        return false;
    }
};