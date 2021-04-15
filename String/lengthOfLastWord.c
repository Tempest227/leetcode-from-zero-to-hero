int lengthOfLastWord(char * s){
    int len = strlen(s);
    char* t = s;
    char* eos = s + len - 1;
    int cnt = 0;
    //长度为1，直接返回
    if (len == 1 && *t != ' ')
    {
        return 1;
    }
    //判断字符串全为空格
    while(*t)
    {
        if (*t == ' ')
        {
            cnt++;
        }
        t++;
    }
    if (len == cnt)
    {
        return 0;
    }
    cnt = 0;
    int flag = 0;//当遇到字母时才置为1
    //从字符串末尾开始遍历
    while(eos >= s)
    {
        if (*eos == ' ')
        {
            if (flag)//第一次遇到空格，第二次遇到字母，然后再遇到空格，结束break
            {
                break;
            }
            else
            {

            }
        }
        else
        {
            flag = 1;
            cnt++;
        }
        eos--;
    }
    
    return cnt;
}