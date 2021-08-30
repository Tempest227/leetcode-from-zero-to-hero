class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int loop = n / 2;
        int mid = n / 2;
        int offset = 1;
        int count = 1;
        int startx = 0;
        int starty = 0;
        int i = 0;
        int j = 0;

        while(loop)
        {
            i = startx;
            j = starty;
            //上行从左到右
            for (; j < starty + n - offset; j++)
            {
                res[i][j] = count++;
            }
            //右列从上到下
            for (; i < starty + n - offset; i++)
            {
                res[i][j] = count++;
            }
            //下行从右到左
            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }
            //左列从下到上
            for (; i > startx; i--)
            {
                res[i][j] = count++;
            }

            startx++;
            starty++;
            offset += 2;
            loop--;
        }
        if (n % 2 != 0)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};