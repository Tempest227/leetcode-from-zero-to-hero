class Solution {
public:
    void reverse(string& s, int start, int end)
    {
        while(start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    void removeExtraSpace(string& s)
    {
        int slowIdx = 0, fastIdx = 0;
        //删除字符串头部空格
        while(s.size() > 0 && fastIdx < s.size() && s[fastIdx] == ' ')fastIdx++;
        //删除字符串中间空格
        while(fastIdx < s.size())
        {
            if (s[fastIdx] == ' ' && fastIdx - 1 > 0 && s[fastIdx - 1] == ' ')
            {
                fastIdx++;
            }
            else
            {
                s[slowIdx] = s[fastIdx];
                slowIdx++;
                fastIdx++;
            }
        }
        //删除字符串尾部空格
        if (slowIdx - 1 > 0 && s[slowIdx - 1] == ' ')
        {
            s.resize(slowIdx - 1);
        }
        else
        {
            s.resize(slowIdx);
        }
    }
    string reverseWords(string s) {
        //1. 移除多余的空格
        removeExtraSpace(s);
        //2. 将每个字符串反转
        reverse(s, 0, s.size() - 1);
        //3. 将每个单词反转
        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            while(j < s.size() && s[j] != ' ')j++;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
};