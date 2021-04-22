

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    if (numbersSize == 0)
    {
        return NULL;
    }
    int left = 0;
    int right = numbersSize - 1;

    while(left <= right)
    {
        if (numbers[left] + numbers[right] > target)
        {
            right--;
        }
        else if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else
        {
            int* res = (int*)malloc(sizeof(int)*2);
            returnSize[0] = 2;
            res[0] = left + 1;
            res[1] = right + 1;
            return res;
        }
    }
    return NULL;
}