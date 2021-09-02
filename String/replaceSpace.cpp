class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldEnd = s.size() - 1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }

        s.resize(s.size() + count * 2);

        int newEnd = s.size() - 1;
        while(newEnd > oldEnd)
        {
            if (s[oldEnd] != ' ')
            {
                s[newEnd] = s[oldEnd];
            }
            else
            {
                s[newEnd] = '0';
                s[newEnd - 1] = '2';
                s[newEnd - 2] = '%';

                newEnd -= 2;
            }
            newEnd--;
            oldEnd--;
        }
        return s;
    }
};