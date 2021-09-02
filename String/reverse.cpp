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
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n % s.size() - 1);
        reverse(s, n % s.size(), s.size() - 1);
        reverse(s, 0, s.size() - 1);

        return s;
    }
};