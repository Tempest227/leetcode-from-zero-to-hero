void moveZeroes(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1)
    {
        return;
    }
    
    int left = 0;
    int right = 1;

    while(right < numsSize)
    {
        if (nums[left] == 0 && nums[right] != 0)
        {
            int t = nums[left];
            nums[left] = nums[right];
            nums[right] = t;

            left++;
            right++;
        }
        else if(nums[left] == 0 && nums[right] == 0)
        {
            right++;
        }
        else
        {
            left++;
            right++;
        }
        
    }
}