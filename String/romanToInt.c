int getValue(char c)
{
    switch(c)
    {
        case 'I':
         return 1;
        case 'V':
         return 5;
        case 'X':
         return 10;
        case 'L':
         return 50;
        case 'C':
         return 100;
        case 'D':
         return 500;
        case 'M':
         return 1000;
    }
    return 0;
}
int romanToInt(char * s){
    int ret=0;
    while((*s!=0)&&((*s+1)!=0))
    {
        char cur=*s;
        char next=*(s+1);
        if(getValue(cur)<getValue(next))
        {
            ret-=getValue(cur);
        }
        else
        {
            ret+=getValue(cur);
        }
        s++;
    }

    return ret;
}