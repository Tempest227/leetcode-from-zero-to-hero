int hammingDistance(int x, int y){
    int i = 0;
    int resXor = x ^ y;
    int cnt = 0;
    int res = 0;
    while(i < 32)
    {
        res = (resXor >> i) & (1);

        if (res != 0)
        {
            cnt++;
        }
        i++;
    }
    return cnt;
}