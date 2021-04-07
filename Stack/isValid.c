char getVal(char c)
{
    switch(c)
    {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
    }
    return 0;
}

bool isValid(char * s){
    int len=strlen(s);
    int i;
    if(len%2!=0)
    {
        return false;
    }
    int stack[len+1];
    int top=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            stack[top++]=s[i];
        }
        else
        {
            if(top==0||getVal(stack[top-1])!=s[i])
            {
                return false;
            }
            else
            {
                top--;
            }
        }
    }
    return top==0;
}