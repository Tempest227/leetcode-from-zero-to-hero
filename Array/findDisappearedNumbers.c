/**
 *原地归位法
 *利用1<=a[i]<=n  =>  0(索引) +1 <= a[i] <= n-1(索引) +1
 */

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    if (numsSize == 0)
    {
        return NULL;
    }
    
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0)
        {
            nums[idx] = -nums[idx];
        }
    }
    
    int cnt = 0;    
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            cnt++;
        }
    }

    int* result = (int*)malloc(sizeof(int) * cnt);
    int j = 0;
    returnSize[0] = cnt;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            result[j] = i + 1;
            j++;
        }
    }
          
    
    return result;
}