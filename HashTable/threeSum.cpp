class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return {};
        }

        if (nums[0] > 0)
        {
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            //去重： nums[i]不变 nums[right]也是指向最后一个元素 若能找到 那么肯定 nums[left]不变，因此要去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //去重
                    while(left < right && nums[right] == nums[right - 1])right--;
                    while(left < right && nums[left] == nums[left + 1])left++;

                    left++;
                    right--;
                }
            }
           
        }
         return result;
    }
};