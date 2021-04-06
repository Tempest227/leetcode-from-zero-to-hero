char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
    {
        return "";
    }
    else if(strsSize==1)
    {
        return strs[0];
    }
    else
    {
        int n=0;
        for(n=0;n<strsSize;n++)
        {
            if(strs[n][0]==0)
                return "";
        }
    }
    
	int i = 0;
	int j = 0;
	int t = strs[0][0];
	int k = 1;

    

	while (strs[k][j] != 0 && t != 0 && k<=strsSize-1)
	{
		if (strs[k][j] == t)
		{			
			if (k == strsSize-1)
			{
				k = 0;
				j++;
				t = strs[k][j];
				
			}	
			k++;	
		}
		else
		{
			break;
		}	
	}
	char* ret = (char*)malloc(sizeof(char)*(j+1));
	
	for (i = 0; i < j; i++)
	{
		ret[i] = strs[0][i];
	}
	ret[i] = '\0';
	return ret;
}