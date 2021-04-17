int myAtoi(char * s){
    if (s == NULL)
    {
        return 0;
    }
    char* t = s;
    int i = 0;
    //跳过空格
    while (i < strlen(s) && s[i] == ' ')
    {
        i++;
    }

    int j = i;
    bool flag = true;
    //遇到符号位
    if (j < strlen(s))
    {
        if(s[j] == '+')
        {
            j++;
        }
        else if (s[j] == '-')
        {
            flag = false;
            j++;
        }
    }
    //处理数字字符，为避免溢出用long
    long result = 0;
    while(j < strlen(s) && isdigit(s[j]))
    {
        result = result * 10 + s[j] - '0';
        if (flag)
        {
            if (result > INT_MAX)
            {
                return INT_MAX;
            }
        }
        else
        {
            if (-result < INT_MIN)
            {
                return INT_MIN;
            }
        }
        j++;
    }
    if (!flag)
    {
        result = -result;
    }
    return (int)result;
}