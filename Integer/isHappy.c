int next(int x)
{
    int t = 0;
    int sum = 0;

    while(x!=0)
    {
        t = x % 10;
        sum += t * t;
        x /= 10;
    }

    return sum;
}

bool isHappy(int n){
    if (n == 1)
    {
        return true;
    }

    int fast = next(n);    
    int slow = n;

    while(slow != fast)
    {
        fast = next(fast);
        fast = next(fast);
        slow = next(slow);

        if(fast == 1)
        {
            return true;
        }
    }

    return false;
}