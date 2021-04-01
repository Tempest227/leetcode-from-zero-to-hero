bool isPalindrome(int x){
    int len=1;
    int t=x;
    if(x<0)
    {
        return false;
    }
    while(t/10!=0)
    {
        len++;
        t/=10;
    }
    
    int i;
    for(i=1;i<=len/2;i++)
    {
        if((x/(int)pow(10,i-1))%10==(x/(int)pow(10,len-i))%10)
        {
            
        }
        else
        {
            return false;
        }
    }
    
    return true;
}