int max(int a, int b)
{
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    if (numsSize == 1)
    {
        return nums[0];
    }

    int dp[numsSize];//dp数组中存储的每个值是：以当前元素结尾的最大的连续子序列的和
    dp[0] = nums[0];
    int result = nums[0];
    for (int i = 1;i < numsSize;i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        result = max(dp[i], result);
    }

    return result;
}