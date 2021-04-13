int singleNumber(int* nums, int numsSize){
    if(numsSize==1)
    {
        return nums[0];
    }
    int i;
    int ret=0;
    for(i=0;i<numsSize;i++)
    {
        ret^=nums[i];
    }
    return ret;
}