/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* arr = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int i;
    int next = 0;
    int total = 0;
    int remainder = 0;
    int j = 0;

    for(i = digitsSize - 1;i >= 0;i--)
    {        
        total = digits[i] + next;
        if (i == digitsSize - 1)
        {
            total++;
        }
        next = total / 10;
        remainder = total % 10;
        arr[j++] = remainder;
    }
    
    if (next != 0)
    {
        arr[j++] = next;
    }
    returnSize[0] = j;

    int left = 0;
    int right = j - 1;
    while(left < right)
    {
        int t = arr[left];
        arr[left] = arr[right];
        arr[right] = t;

        left++;
        right--;
    }

    return arr;
}