int compare( const void *arg1, const void *arg2 )
{
   return (*(int*)arg1 - *(int*)arg2);
}

int majorityElement(int* nums, int numsSize){
    if (numsSize == 1)
    {
        return nums[0];
    }

    qsort(nums, numsSize, sizeof(int),compare);

    int i = 0;    
    int cnt = 1;
    int max = 0;
    int result = 0;
    
    while(i < numsSize)
    {
        if (i + 1 < numsSize)
        {
            if (nums[i] == nums[i + 1])
            {
                cnt++;
                if (cnt > numsSize / 2)
                {
                    max = max > cnt ? max : cnt;
                    result = nums[i];
                }
                    
            }
            else
            {
                cnt = 1;
            }
        }
        i++;
    }
    return result;
}