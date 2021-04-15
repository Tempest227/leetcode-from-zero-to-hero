char * addBinary(char * a, char * b){
    if(strcmp(a, "0") == 0)
    {
        return b;
    }
    if(strcmp(b, "0") == 0)
    {
        return a;
    }
	int lenA = strlen(a);
	int lenB = strlen(b);
	int resLen = lenA > lenB ? lenA + 2 : lenB + 2;

	int k = 0;
	int j = 0;
	int i = 0;
	
	char* res = (char*)malloc(sizeof(char)* resLen);
	memset(res, 0, sizeof(char)* resLen);

	char total = 0;
	char next = 0;
	int remainder = 0;

	for (i = lenA - 1, j = lenB - 1; i >= 0 && j >= 0; i--, j--)
	{
		char charA = a[i] - '0';
		char charB = b[j] - '0';

		total = charA + charB + next;
		next = total / 2;
		remainder = total % 2;

		res[k++] = (remainder == 1 ? '1' : '0');
	}

	while (i >= 0)
	{
		char charA = a[i] - '0';
		total = charA + next;
		next = total / 2;
		remainder = total % 2;
		i--;
		res[k++] = (char)remainder + '0';
	}

	while (j >= 0)
	{
		char charB = b[j] - '0';
		total = charB + next;
		next = total / 2;
		remainder = total % 2;
		j--;
		res[k++] = (char)remainder + '0';
	}
	if (next != 0)
	{
		res[k++] = '1';
	}
    
    res[k] = '\0';
	int left = 0;
    int right = strlen(res) - 1;

    while (left < right)
	{
		char t = res[left];
		res[left] = res[right];
		res[right] = t;

		left++;
		right--;
	}

	return res;
}