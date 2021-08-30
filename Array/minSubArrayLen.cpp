class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int i = 0;
        int j = 0;
        int subLen = 0;
        int sum = 0;

        for (j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while(sum >= target)
            {
                subLen = j - i + 1;
                result = result < subLen ? result : subLen;
                sum -= nums[i];
                i++;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
 