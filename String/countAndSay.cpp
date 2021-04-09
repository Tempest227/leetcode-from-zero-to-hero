class Solution {
public:
    string getDesc(string desc)
    {
        char table[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        if((desc.compare("1"))==0)
        {
            return "11";
        }
        int start=0;
        int end=1;
        int len = desc.length();
        string res;
        while(end<=len)
        {
            char s=desc[start];
            if(end==len)
            {
                res.append(1,table[end-start]).append(1,s);
                break;
            }
            char e=desc[end];
            if(s==e)
            {
                end++;
            }else{
                res.append(1,table[end-start]).append(1,s);
                start=end;
                end++;
            }
            
        }
        return res;
    }
    string countAndSay(int n) {
        string result="1";
        if(n==1)
        {
            return result;
        }
        else
        {
            for(int i=1;i<=n-1;i++)
            {
                result=getDesc(result);
            }
        }
        return result;
    }
};