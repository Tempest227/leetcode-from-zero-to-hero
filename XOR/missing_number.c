//sum1-sum2
int missingNumber(int* nums, int numsSize){
    int i=0,t=0;
    for(i=0;i<numsSize;i++)
    {
        t += (i+1);//sum1
    }
    for(i=0;i<numsSize;i++)
    {
        t -= nums[i];//sum2
    }
    return t;
}
//xor
int missingNumber(int* nums, int numsSize){
    int i=0,t=0;
    for(i=0;i<numsSize;i++)
    {
        t = t^(i+1);
    }
    for(i=0;i<numsSize;i++)
    {
        t = t^nums[i];
    }
    return t;
}
``