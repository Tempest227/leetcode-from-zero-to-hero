int removeDuplicates(int* nums, int numsSize){
    int src;
    int dst=0;
    if(numsSize==0)
    {
        return 0;
    }
    for(src=1;src<numsSize;src++)
    {
        if(nums[dst]!=nums[src])
        {
            dst++;
            nums[dst]=nums[src];
        }
    }
    return dst+1;
}   