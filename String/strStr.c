int strStr(char * haystack, char * needle){    
    char*start=haystack;
    char*end=haystack;
    char*sub=needle;
    if(*needle=='\0')
    {
        return 0;
    }
    while(*start!='\0')
    {
        if(*start==*sub)
        {
            end = start;
            while(*end==*sub&&*end!='\0'&&*sub!='\0')
            {
                end++;
                sub++;
            }
            if(*sub=='\0')
            {
                return start-haystack;
            }
            else
            {
                sub=needle;
            }
        }
        start++;
    }
    
    return -1;
}