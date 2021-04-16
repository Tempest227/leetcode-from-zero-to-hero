int mySqrt(int x){
    double a = 8;
    double b;
    while(1)
    {
        //《最优化》牛顿法
        b = (a + x / a) / 2;
        
        if (abs(a - b) < 1)
        {
            break;
        }
        a = b;
    }
    return (int)b;
}