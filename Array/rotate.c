//超出时间限制
// void rotate(int* nums, int numsSize, int k){

    // int i;
    // k%=numsSize;
    // while(k>0)
    // {
        
        // int t=nums[numsSize-1];
        // for(i=numsSize-2;i>=0;i--)
        // {
            // nums[i+1]=nums[i];
        // }
        // nums[0]=t;

        // k--;
    // }
// }

void rev(int* nums, int start, int end)
{
    while(start<end)
    {
        int t=nums[start];
        nums[start]=nums[end];
        nums[end]=t;

        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k%=numsSize;
    rev(nums,0,numsSize-k-1);
    rev(nums,numsSize-k,numsSize-1);
    rev(nums,0,numsSize-1);
}