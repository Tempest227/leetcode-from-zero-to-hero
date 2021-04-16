int climbStairs(int n){
    if (n == 1 || n == 2)
    {
        return n;
    }

    int a = 1;
    int b = 2;
    int c;

    while(n-- > 2)//相当于非递归形式的斐波那契数列
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}