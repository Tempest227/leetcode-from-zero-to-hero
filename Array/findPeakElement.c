int findPeakElement(int* nums, int numsSize){    
    if (numsSize == 1)
    {
        return 0;
    }
    if (numsSize == 2)
    {
        return nums[0] > nums[1] ? 0 : 1;
    }
    int left = 0;
    int right = 2;
    int flag = 0;

    if (nums[left] > nums[left + 1])
    {
        return left;
    }

    while(right < numsSize)
    {
        if (nums[left + 1] > nums[left] && nums[left + 1] > nums[right])
        {
            flag = 1;
            break;
        }
        left++;
        right++;
    }

    if (flag)
    {
        return left + 1;
    }
    else if (nums[right - 1] > nums[left])
    {
        return right - 1;
    }
    return 0;
}