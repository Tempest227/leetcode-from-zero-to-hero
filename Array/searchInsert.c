int searchInsert(int* nums, int numsSize, int target){
    if(numsSize==0||target<nums[0])
    {
        return 0;
    }
    if(numsSize==1)
    {
       return (nums[0]>=target)?0:1;
    }
    int i1=0;
    int i2=1;

    while(i2<numsSize)
    {
        if(target>nums[i1]&&target<nums[i2])
        {
            return i2;
        }
        if(target==nums[i1])
        {
            return i1;
        }
        if(target==nums[i2])
        {
            return i2;
        }
        i1++;
        i2++;
    }
    return numsSize;
}